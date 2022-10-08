#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<ctime>
#include<cassert>
using namespace std;
#define y1 fndjifhwdn
#define ws vfsdkofsjd
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
ll gcd(ll a,ll b){
	if (b==0) return a;
	return gcd(b,a%b);
}
vector<pair<ll,int> > v;
int main(){
	#ifdef home
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll a,b,d;
	cin>>a;
	cin>>b;
	d=a*b/gcd(a,b);
	if (a<b){
		for (int i=0;i*a<=d;i++){
			v.pb(mp(i*a,1));
		}                
		for (int i=0;i*b<=d;i++){
			v.pb(mp(i*b,0));
		}
	} else {
		for (int i=0;i*a<=d;i++){
			v.pb(mp(i*a,0));
		}
		for (int i=0;i*b<=d;i++){
			v.pb(mp(i*b,1));
		}
	}
	sort(v.begin(),v.end());
	ll s1,s2;
	s1=0;
	s2=0;
	for (int i=0;i<(int)v.size()-1;i++){
		if (v[i+1].sc==0){
			s1+=v[i+1].fs-v[i].fs;
		} else
			s2+=v[i+1].fs-v[i].fs;
	}
//	cerr<<s1<<" "<<s2<<endl;
	if (a>b){
		if (s1>s2) printf("Dasha\n");
		if (s1<s2) printf("Masha\n");
	} else {
		if (s1<s2) printf("Dasha\n");
		if (s1>s2) printf("Masha\n");
	}
	if (s1==s2) printf("Equal\n");



    return 0;
}