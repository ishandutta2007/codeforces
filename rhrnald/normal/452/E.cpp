#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <complex>
 
#define sz(v) ((int)((v).size()))
#define all(v) (v).begin(), (v).end()
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
 
const int INF = 0x3c3c3c3c;
const ll LINF = 1ll*INF*INF*2;
const int MOD=1000000007;
 
const int N = 300011;
int n,m;
 
string s1,s2,s3;
vector<int> v[N], A2, L2, pos;
int cnt[N][4];
int check(int x) {
	if(x==sz(s1)+1) return 0;
	if(x==sz(s1)+sz(s2)+2) return 0;
	if(x<=sz(s1)) return 1;
	if(x<=sz(s1)+sz(s2)+1) return 2;
	return 3;
}
int M(int x) {
	if(x==sz(s1)+1) return 0;
	if(x==sz(s1)+sz(s2)+2) return 0;
	if(x==sz(s1)+sz(s2)+sz(s3)+3) return 0;
	if(x<=sz(s1)) return sz(s1)-x+1;
	if(x<=sz(s1)+sz(s2)+1) return sz(s1)+sz(s2)+2-x;
	return sz(s1)+sz(s2)+sz(s3)+3-x;
}
int ans[N];
ll sum;
int p[N];
int c[N][4];
int h(int cur) {
	if(p[cur]==cur) return cur;
	p[cur]=h(p[cur]);
	return p[cur];
}
ll f(int x) {
	return (1ll*c[x][1]*c[x][2]%MOD)*c[x][3]%MOD;
}
void add(int x, int y) {
	x=h(x), y=h(y);
	sum-=f(x)+f(y);
	for(int i=1; i<=3; i++) c[x][i]+=c[y][i];
	p[y]=x;
	sum+=f(x);
	sum=(sum+MOD)%MOD;
}
void RadixSort(vector<ppi> &v) {
	vector<ppi> nv; nv.resize(sz(v));
	int lim=max(sz(v), 256)+5;
	lim=lim+lim;
	vector<int> cnt=vector<int>(lim, 0);
	for(int i=0;i<sz(v);i++) cnt[v[i].first.second]++;
	for(int i=1;i<lim;i++) cnt[i]+=cnt[i-1];
	for(int i=sz(v)-1; i>=0; i--) nv[--cnt[v[i].first.second]]=v[i];
 
	cnt.clear(); cnt.resize(lim, 0);
	for(int i=0;i<sz(v);i++) cnt[nv[i].first.first]++;
	for(int i=1;i<lim;i++) cnt[i]+=cnt[i-1];
	for(int i=sz(v)-1; i>=0; i--) v[--cnt[nv[i].first.first]]=nv[i];
}
 
int lll;
vector<int> ao,ae;
 
vector<vector<pii>> OT,ET;
void makeOddRMQ(vector<int> &Lo) {
	OT.clear();
	OT.push_back(vector<pii>());
	for(int i=0; i<sz(Lo); i++) OT[0].push_back({Lo[i],i});
	for(int i=1,l=1; l<sz(Lo); i++, l=l+l){
		OT.push_back(vector<pii>());
		for(int j=0; j+l+l<sz(Lo); j++) {
			OT[i].push_back(min(OT[i-1][j], OT[i-1][j+l]));
		}
	}
}
void makeEvenRMQ(vector<int> &Le) {
	ET.clear();
	ET.push_back(vector<pii>());
	for(int i=0; i<sz(Le); i++) ET[0].push_back({Le[i],i});
	for(int i=1,l=1; l<sz(Le); i++, l=l+l) {
		ET.push_back(vector<pii>());
		for(int j=0; j+l+l<sz(Le); j++) {
			ET[i].push_back(min(ET[i-1][j], ET[i-1][j+l]));
		}
	}
}
pii OddRMQ(int l, int r) {
	if(l==r) return {lll-ao[l]+1,r};
	if(l>r) swap(l,r);r--;
	int d=1, i=0;
	while(d+d<=r-l+1) d=d+d, i++;
	return min(OT[i][l], OT[i][r-d+1]);
}
pii EvenRMQ(int l, int r) {
	if(l==r) return {lll-ae[l]+1,r};
	if(l>r) swap(l,r);r--;
	int d=1,i=0;
	while(d+d<=r-l+1) d=d+d, i++;
	return min(ET[i][l], ET[i][r-d+1]);
}
 
struct query{int w,x,y,z;};
void SA(int len, vector<int> &T, vector<int> &A, vector<int> &L) {
	if(len==1) {
		A.clear(); L.clear();
		A.resize(3,0); L.resize(3,0);
		A[1]=1;
		return;
	}

	int olen=(len+1)/2, elen=len/2;
	vector<int> Ao,Ae,Lo,Le,oloc,eloc;
	vector<int> optr, eptr, ofin, efin, olst, elst;
	//Construct odd SA
	vector<ppi> v;
	for(int i=1; i<=olen; i++) v.push_back({{T[i+i-1], T[i+i]}, i}); //T[len+1]=0  
	RadixSort(v);
	vector<int> nT; nT.resize(olen+5);
	int idx=1; nT[v[0].second]=1;
	for(int i=1; i<olen; i++) {
		if(v[i].first!=v[i-1].first) idx++;
		nT[v[i].second]=idx;
	}
	nT.push_back(0);
	SA(olen, nT, Ao, Lo);
	A.resize(len+1); L.resize(len+1);
	lll=len;
	for(int i=1; i<=olen; i++) Ao[i]=Ao[i]+Ao[i]-1;
	for(int i=1; i<=olen-1; i++) {
		Lo[i]=Lo[i]+Lo[i];
		if(T[Ao[i]+Lo[i]]==T[Ao[i+1]+Lo[i]]) Lo[i]++; //T[len+1]=0 out of index  
	}
	ao=Ao;
	makeOddRMQ(Lo);

	oloc.resize(len+5);
	for(int i=1; i<=olen; i++) oloc[Ao[i]]=i; oloc[len+1]=0;

	//Construct even SA
	lll=len;
	v.clear();
	for(int i=1; i<=elen; i++) v.push_back({{T[i+i], oloc[i+i+1]}, i+i}); //out of index 
	RadixSort(v);

	Ae.resize(elen+5);
	for(int i=1; i<=elen; i++) Ae[i]=v[i-1].second;

	Le.resize(elen+5);
	Le[0]=Le[elen]=0;
	for(int i=1; i<elen;i++) {
		if(T[Ae[i]]!=T[Ae[i+1]]) Le[i]=0;
		else Le[i]=1+OddRMQ(oloc[Ae[i]+1], oloc[Ae[i+1]+1]).first;
	}
	ae=Ae;
	makeEvenRMQ(Le);

	eloc.resize(len+5);
	for(int i=1; i<=elen; i++) eloc[Ae[i]]=i; eloc[len+1]=0;

	//Merge
	A.resize(len+5); L.resize(len+5);

	vector<vector<query>> Q; Q.resize(len);

	optr.resize(len+5,0);eptr.resize(len+5,0);ofin.resize(len+5,0);efin.resize(len+5,0);elst.resize(len+5,0);olst.resize(len+5,0);

	Q[0].push_back({1, olen, 1, elen});
	optr[olen]=elen; eptr[elen]=olen;
	for(int k=0; k<len; k++) {
		for(query &cur :Q[k]) {
			int w=cur.w, x=cur.x, y=cur.y, z=cur.z;
			int e,d;
			if(k==0) e=0;
			else if(k==1) e=1;
			else {
				if(OddRMQ(w,x).first==k) {
					int ww=eloc[Ao[w]+1];
					int xx=eloc[Ao[x]+1];
					int zz=oloc[Ae[z]+1];
					if(efin[ww]) e=min(elst[ww], OddRMQ(eptr[ww], zz).first)+1;
					else e=OddRMQ(eptr[EvenRMQ(ww,xx).second], zz).first+1;
				} else {
					int yy=oloc[Ae[y]+1];
					int zz=oloc[Ae[z]+1];
					int xx=eloc[Ao[x]+1];
					if(ofin[yy]) e=min(olst[yy], EvenRMQ(optr[yy], xx).first)+1;
					else e=EvenRMQ(optr[OddRMQ(yy,zz).second], xx).first+1;
				}
			}
			e=min(e,k);

			if(k==e) {
				int o_idx=w;
				int e_idx=y;
				int Po=w;
				int Pe=y;
				while(o_idx<=x || e_idx<=z) {
					pii to=OddRMQ(o_idx, x);
					pii te=EvenRMQ(e_idx, z);
					int o_nxt=(to.first==k)? to.second: x;
					int e_nxt=(te.first==k)? te.second: z;
					int co=(o_idx<=x)? T[Ao[o_idx]+k] : INF; // out of index error  x
					int ce=(e_idx<=z)? T[Ae[e_idx]+k] : INF; // out of index error  x
					if(co==ce) {
						int M=min(OddRMQ(o_idx,o_nxt).first, EvenRMQ(e_idx,e_nxt).first);
						M=min(M,len-1);
						Q[M].push_back({o_idx, o_nxt, e_idx, e_nxt});
						if(o_nxt+e_nxt<x+z) L[o_nxt+e_nxt]=k;
						
						optr[o_nxt]=e_nxt;
						eptr[e_nxt]=o_nxt;

						o_idx=o_nxt+1;
						e_idx=e_nxt+1;
					}
					if(co<ce) {
						for(int i=o_idx; i<=o_nxt; i++) A[e_idx+i-1]=Ao[i], ofin[i]=1;//e_idx+i-1;
						for(int i=o_idx; i<o_nxt; i++) L[e_idx+i-1]=Lo[i];
						if(e_idx+o_nxt-1<cur.x+cur.z) L[e_idx+o_nxt-1]=k;

						for(int i=o_idx; i<=o_nxt; i++) optr[i]=Pe, olst[i]=e;
						o_idx=o_nxt+1;
					}
					if(co>ce) {
						for(int i=e_idx; i<=e_nxt; i++) A[o_idx+i-1]=Ae[i], efin[i]=1;//o_idx+i-1;

						for(int i=e_idx; i<e_nxt; i++) L[o_idx+i-1]=Le[i];
						if(o_idx+e_nxt-1<cur.x+cur.z) L[o_idx+e_nxt-1]=k;

						for(int i=e_idx; i<=e_nxt; i++) eptr[i]=Po, elst[i]=e;
						e_idx=e_nxt+1;
					}
				}
			} else {
				if(T[Ao[w]+e]<T[Ae[y]+e]) {
					for(int i=w; i<=x; i++) A[y+i-1]=Ao[i], L[y+i-1]=Lo[i], ofin[i]=1;//y+i-1;
					for(int i=w; i<=x; i++) optr[i]=y, olst[i]=e;
					L[x+y-1]=e;
					
					for(int i=y; i<=z; i++) A[x+i]=Ae[i], efin[i]=1;//x+i;
					for(int i=y; i<z; i++) L[x+i]=Le[i];
					for(int i=y; i<=z; i++) eptr[i]=w, elst[i]=e;
					// L  
				} else {
					for(int i=y; i<=z; i++) A[w+i-1]=Ae[i], L[w+i-1]=Le[i], efin[i]=1;//w+i-1;
					for(int i=y; i<=z; i++) eptr[i]=w, elst[i]=e;
					L[w+z-1]=e;
					
					for(int i=w; i<=x; i++) A[z+i]=Ao[i], ofin[i]=1;//z+i;
					for(int i=w; i<x; i++) L[z+i]=Lo[i];
					for(int i=w; i<=x; i++) optr[i]=y, olst[i]=e;
					
				}
			}
		}
	}
}
class SuffixArray {
public:
	string s;
	int n;
	SuffixArray(string _s){
		s = _s;
		n = s.size();
	}
 
	vector<int> m,idx,sfx,cnt,temp;
	void getSFX() {
		int lim = max(n+1, 257);
		m.resize(n+1); idx.resize(n+1); sfx.resize(n+1);temp.resize(n+1);
		for(int i=0; i<n; i++) m[i] = s[i];
		for(int i=0; i<n; i++) sfx[i] = i;
 
		for(int d=1; d<n; d=d+d) {
			cnt=vector<int>(lim, 0);
			for(int i=0; i<n; i++) cnt[m[min(n, i+d)]]++;
			for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
			for(int i=n-1; i>=0; i--) idx[--cnt[m[min(n,i+d)]]] = i;
 
			cnt=vector<int>(lim,0);
			for(int i=0; i<n; i++) cnt[m[i]]++;
			for(int i=1; i<lim; i++) cnt[i]+=cnt[i-1];
			for(int i=n-1; i>=0; i--) sfx[--cnt[m[idx[i]]]] = idx[i];
 
			temp[sfx[0]] = 1;
			for(int i=1; i<n; i++) {
				if((m[sfx[i]] == m[sfx[i-1]]) && (m[sfx[i]+d] == m[sfx[i-1]+d])) temp[sfx[i]] = temp[sfx[i-1]];
				else temp[sfx[i]] = temp[sfx[i-1]]+1;
			}
			m = temp;
		}
 
		//return sfx;
	}
	
	vector<int> loc;
	vector<int> lcp;
	void getLCP() {
		loc.resize(n); lcp.resize(n);
		for(int i=0; i<n; i++) loc[sfx[i]] = i;
 
		int k=0;
		for(int i=0; i<n; i++) {
			int l = loc[i];
			if(l==0) {k=0; continue;}
			if(k) k--;
 
			while(s[i+k] == s[sfx[l-1]+k]) k++;
			lcp[l] = k;
		}
		
	}
 
 
};
void SA2(int len, vector<int> &T, vector<int> &A, vector<int> &L, string &s) {
	SuffixArray sa = SuffixArray(s);
	sa.getSFX();
	sa.getLCP();
	A.resize(len+1,0); L.resize(len+1,0);
	for(int i=0;i<len;i++) A[i+1]=sa.sfx[i]+1;
	for(int i=1;i<len;i++) L[i]=sa.lcp[i];
}
string nxt(string s) {
	for(int i=0; i<sz(s); i++) {
		if(s[i]<'c') {s[i]=s[i]+1; return s;}
		s[i]='a';
	}
	s.append("a");
	return s;
}
int main(void){
	cin >> s1 >> s2 >> s3;
	string s=s1+"#"+s2+"#"+s3+"#";
	n=sz(s);
	vector<int> T, A, L;
	T.resize(n+3,0);
	for(int i=0; i<n; i++) T[i+1]=s[i];
	//SA2(n,T,A2,L2,s);
	SA(n,T,A,L);
	//for(int i=1; i<=n;i++) if(A[i]!=A2[i]) printf("wow ",i); printf("\n");
//	for(int i=1; i<=n; i++) cout << A[i] << ':' << s.substr(A[i]-1) << endl;
	int m=min({sz(s1), sz(s2), sz(s3)});
	for(int i=1; i<n; i++) L[i]=min(min(L[i],m), min(M(A[i]), M(A[i+1])));
	for(int i=1; i<n; i++) v[L[i]].push_back(i);
	for(int i=1; i<=n; i++) p[i]=i;
	for(int i=1; i<=n; i++) c[A[i]][check(A[i])]=1;
	for(int i=m; i>=1; i--) {
		for(int e : v[i]) add(A[e], A[e+1]);
		ans[i]=sum;
	}
	for(int i=1; i<=m; i++) printf("%d ", ans[i]);
}