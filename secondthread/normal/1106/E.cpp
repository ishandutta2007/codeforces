#include <bits/stdc++.h>
using namespace std;
const int maxTimes=100002;
const int maxInterrupts=201;
typedef long long ll;
ll dp[maxInterrupts][maxTimes];

int nTimes, interrupts, nEnvelopes;	

struct Envelope {
	int start, end, nextAllowed, money, id;
	Envelope(int start, int end, int nextAllowed, int money, int id):
		start(start), end(end), nextAllowed(nextAllowed), money(money), id(id) {}
};

bool envStartLT(const Envelope& l, const Envelope& r) {
	if (l.start!=r.start) return l.start<r.start;
	return l.id<r.id;
}
struct EnvMoneyGT {
	bool operator() (const Envelope& l, const Envelope& r) {
		if (l.money!=r.money) return l.money>r.money;
		if (l.nextAllowed!=r.nextAllowed) return l.nextAllowed>r.nextAllowed;
		return r.id>l.id;
	}
};

ll go(int interrupts, int time, vector<Envelope*> &bestAtTime) {
	if (time==nTimes) return 0;
	if (dp[interrupts][time]!=-1) return dp[interrupts][time];
	ll best;
	Envelope* cur=bestAtTime[time];
	if (cur!=NULL)assert(cur->nextAllowed+1>time);
	if (cur==NULL)
		best=go(interrupts, time+1, bestAtTime);
	else
		best=cur->money+go(interrupts, cur->nextAllowed+1, bestAtTime);
	
	if (interrupts>0) {
		best=min(best, go(interrupts-1, time+1, bestAtTime));
	}
	return dp[interrupts][time]=best;
}

int main() {
	cin>>nTimes>>interrupts>>nEnvelopes;
	nTimes++;
	vector<Envelope> envelopes; envelopes.reserve(nEnvelopes);
	for (int i=0; i<maxInterrupts; i++)
		for (int j=0; j<maxTimes; j++)
			dp[i][j]=-1;
	for (int i=0; i<nEnvelopes; i++) {
		int s, t, d, m; cin>>s>>t>>d>>m;
		envelopes.emplace_back(s, t, d, m, i);
	}
	sort(envelopes.begin(), envelopes.end(), envStartLT);
	for (int i=0; i<nEnvelopes; i++) envelopes[i].id=i;
	set<Envelope, EnvMoneyGT> s;
	vector<Envelope*> bestAtTime(nTimes, NULL);
	int envelopeIndex=0;
	for (int i=0; i<nTimes; i++) {
		while (envelopeIndex<nEnvelopes && i>=envelopes[envelopeIndex].start) {
			s.insert(envelopes[envelopeIndex]);
			envelopeIndex++;
		}
		while (s.begin()!=s.end()) {
			if (s.begin()->end<i) {
				s.erase(s.begin());
			}
			else {
				bestAtTime[i]=&(envelopes[s.begin()->id]);
				break;
			}
		}
		//if (i>=1) cout<<"Money at time "<<i<<": "<<bestAtTime[i]->money<<'\n';
	}
	for (int i=0; i<=interrupts; i++)
		for (int j=nTimes-1; j<=0; j--)
			go(i, j, bestAtTime);
	ll ans=go(interrupts, 0, bestAtTime);
	cout<<ans<<endl;

	return 0;
}