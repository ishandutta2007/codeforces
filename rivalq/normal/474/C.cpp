#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define ll             long long
#define int            long long
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define mem0(a)        memset(a,0,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define hell           1000000007
#define elasped_time   1.0 * clock() / CLOCKS_PER_SEC
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}
pii rotate(int d,pii p,pii a){
	p.x=p.x*4;
	p.y=p.y*4;
	a.x=a.x*4;
	a.y=a.y*4;
	int x=p.x-a.x;
	int y=p.y-a.y;
	if(d==0)return p;
	else if(d==1){
		return{-y+a.x,x+a.y};
	}
	else if(d==2){
		return {-x+a.x,-y+a.y};
	}
	else{
        return {y+a.x,-x+a.y};
	}
}
bool ch(pii p1,pii p2,pii p3,pii p4){
	 if(p1==p2 || p2==p3 || p3==p4 || p4==p1 || p2==p4 || p3==p1)return 0;
	 int xcent=p1.x+p2.x+p3.x+p4.x;
	 int ycent=p1.y+p2.y+p3.y+p4.y;
     xcent/=4;
     ycent/=4;
	 int x1=p1.x-xcent;
	 int y1=p1.y-ycent;
	 int x2=-y1;
	 int y2=x1;
	 vector<pii>v1,v2;
	 v1.eb(p2);v1.eb(p3),v1.eb(p4);
	 sort(all(v1));
	 v2.eb(xcent-x1,ycent-y1);
	 v2.eb(xcent+x2,ycent+y2);
	 v2.eb(xcent-x2,ycent-y2);
	 sort(all(v2));
	 return v1[0]==v2[0] && v1[1]==v2[1] && v1[2]==v2[2]; 
}
int solve(){
 pii p1,p2,p3,p4,a1,a2,a3,a4;
 pii q1,q2,q3,q4;
 cin>>p1>>a1>>p2>>a2>>p3>>a3>>p4>>a4;
 int mi=hell;
 for(int i=0;i<4;i++){
 	for(int j=0;j<4;j++){
 		for(int k=0;k<4;k++){
 			for(int l=0;l<4;l++){
                q1=rotate(i,p1,a1);
                q2=rotate(j,p2,a2);
                q3=rotate(k,p3,a3);
                q4=rotate(l,p4,a4);
                if(ch(q1,q2,q3,q4)){
                	mins(mi,i+j+k+l);
                }
 			}
 		}
 	}
 }
 if(mi==hell)cout<<-1<<endl;
 else cout<<mi<<endl;
 return 0;
}
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
    sieve();
    #endif
    #ifdef NCR
    init();
    #endif
    int t=1;cin>>t;
    while(t--){
        solve();
    }
    return 0;
}