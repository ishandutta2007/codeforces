#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxLen=2000001;
const ll m1=8675309, m2=1000000007;
const ll s1=257, s2=619;
ll s1Pow[maxLen], s2Pow[maxLen];

void HarmeyerHashPrecomp() {
	s1Pow[0]=s2Pow[0]=1;
	for (int i=1; i<maxLen; i++)
		s1Pow[i]=(s1Pow[i-1]*s1)%m1;
	for (int i=1; i<maxLen; i++)
		s2Pow[i]=(s2Pow[i-1]*s2)%m2;
}

struct HarmeyerHash {
	ll v1, v2;

	HarmeyerHash(): v1(0), v2(0) {}
	HarmeyerHash(ll v1, ll v2): v1(v1), v2(v2) {}

	void add(int o) {
		v1=(v1*s1+o)%m1;
		v2=(v2*s2+o)%m2;
	}

	//distFromEnd==0 if last character, 1 if second last character, etc.
	void change(int distFromEnd, int to, int old) {
		ll d1=(to-old)*s1Pow[distFromEnd];
		ll d2=(to-old)*s2Pow[distFromEnd];
		v1=((v1+d1)%m1+m1)%m1;
		v2=((v2+d2)%m2+m2)%m2;
	}

	bool operator<(const HarmeyerHash &o) const {
		if (v1!=o.v1) return v1<o.v1;
		return v2<o.v2;
	}

	bool operator==(const HarmeyerHash &o) const {return v1==o.v1&&v2==o.v2;}
	bool operator!=(const HarmeyerHash &o) const {return !operator==(o);}

	static vector<HarmeyerHash> getPrefixHashes(string word) {
		int n=word.length();
		vector<HarmeyerHash> ans;
		ans.push_back(HarmeyerHash());
		for (int i=0; i<n; i++) {
			ans.push_back(ans[i]);
			ans[i+1].add(word[i]);
		}
		return ans;
	}

	//inclusive, exclusive
	static HarmeyerHash substringHash(vector<HarmeyerHash> &prefixHashes,
			int from, int to) {
		if (from==to) return HarmeyerHash();
		HarmeyerHash old=prefixHashes[to], toSub=prefixHashes[from];
		int diff=to-from;
		old.v1=(old.v1-(toSub.v1*s1Pow[diff])%m1+m1)%m1;
		old.v2=(old.v2-(toSub.v2*s2Pow[diff])%m2+m2)%m2;
		return old;
	}
};

bool hasTri(vector<bool> a) {
	for (int mid=0; mid<a.size(); mid++) {
		for (int l=0; l<mid; l++) {
			int r=mid+(mid-l);
			if (r>=a.size()) continue;
			if (a[l]==a[mid]&&a[mid]==a[r])
				return true;
		}
	}
	return false;
}

void print(vector<bool> a) {
	for (int i=0; i<a.size(); i++)
		cout<<(a[i]?'1':'0');
	cout<<endl;
}

set<HarmeyerHash> validHashes;

void precomp() {
	for(int nDigits=0; nDigits<10; nDigits++) {
		for (int val=0; val<1<<nDigits; val++) {
			vector<bool> a;
			for (int i=0; i<nDigits; i++) {
				if (val&(1<<i))
					a.push_back(true);
				else 
					a.push_back(false);
			}
			if (hasTri(a)) continue;
			HarmeyerHash toAddTo;
			for (int i=0; i<a.size(); i++)
				toAddTo.add(a[i]?'1':'0');
			validHashes.insert(toAddTo);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	precomp();
	string line; cin>>line;
	int n=line.size();
	vector<HarmeyerHash> prefixHashes=HarmeyerHash::getPrefixHashes(line);
	HarmeyerHashPrecomp();
	ll nIllegal=0;
	for (int start=0; start<n; start++) {
		//HarmeyerHash curHash;
		for (int end=start; end<n&&end-start+1<=10; end++) {
			//curHash.add(line[end]);
			HarmeyerHash sub=HarmeyerHash::substringHash(prefixHashes, start, end+1);
			if (validHashes.count(sub)) {
				nIllegal++;
			}
			else
				break;
		}
	}
	ll ans=n*(ll)(n+1)/2-nIllegal;
	cout<<ans<<endl;
	return 0;
}