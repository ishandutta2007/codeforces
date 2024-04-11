#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second

using namespace std;
using LL = long long;
using pii = pair<int, int>;

pii operator - (const pii& a, const pii& b) {return {a.x-b.x, a.y-b.y};}
LL operator ^ (const pii& a, const pii& b) {return a.x*b.y-a.y*b.x;}

pii p[1111];

LL que(int a, int b, int c, int d) {
	//if(a == 1) return abs(p[c]-p[b]^p[d]-p[b]); return p[c]-p[b]^p[d]-p[b];

	LL ans;
	printf("%d %d %d %d\n", a, b, c, d);
	fflush(stdout);
	scanf("%I64d", &ans);
	return ans;
}

LL area[1111], sgn[1111];

int main() {
#ifdef KN
	//freopen("D.in", "r", stdin);
	//freopen("out.out", "w", stdout);
#endif // KN
	int n;
	cin>>n;

	//for(int i=1; i<=n; i++) cin>>p[i].x>>p[i].y;

    for(int i=3; i<=n; i++) {
		area[i]=que(1, 1, 2, i);
		sgn[i]=que(2, 1, i, 2);
    }

    vector<int> id, ans, fst, snd;
    ans.pb(1);
    for(int i=3; i<=n; i++) {
		if(sgn[i]>0) id.pb(i);
    }

    sort(id.begin(), id.end(), [&](int i, int j) {return area[i]<area[j];});
    int L=1, R=2;
	for(int i=0; i<id.size(); i++) {
		if(i+1<id.size()) {
			int I=id[i], J=id[i+1];
			if(que(2, L, I, J)>0) fst.pb(I), R=I;
			else snd.pb(I), L=I;
		}else fst.pb(id[i]);
	}
	for(int i=0; i<fst.size(); i++) ans.pb(fst[i]);
	reverse(snd.begin(), snd.end());
	for(int i=0; i<snd.size(); i++) ans.pb(snd[i]);

	ans.pb(2);


	id.clear(), fst.clear(), snd.clear();
	for(int i=3; i<=n; i++) {
		if(sgn[i]<0) id.pb(i);
    }

    sort(id.begin(), id.end(), [&](int i, int j) {return area[i]<area[j];});


    L=2, R=1;
	for(int i=0; i<id.size(); i++) {
		if(i+1<id.size()) {
			int I=id[i], J=id[i+1];
			if(que(2, L, I, J)>0) fst.pb(I), R=I;
			else snd.pb(I), L=I;
		}else fst.pb(id[i]);
	}

	for(int i=0; i<fst.size(); i++) ans.pb(fst[i]);
	reverse(snd.begin(), snd.end());
	for(int i=0; i<snd.size(); i++) ans.pb(snd[i]);

	printf("0");
	for(int i=0; i<ans.size(); i++) cout<<' '<<ans[i];
	cout<<endl;
	fflush(stdout);

	return 0;
}