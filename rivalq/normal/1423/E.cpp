
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse4,sse4.2,popcnt,abm,mmx,avx")

#include<bits/stdc++.h>

#define rep(i,a,n)     for(int i=a;i<n;i++)
#define pb             push_back
#define endl           "\n"
#define x              first
#define y              second
#define sz(a)          (int)a.size()
using namespace std;


template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.x>>a.y;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.x<<" "<<a.y;return out;}
template<typename T,typename T1>T maxs(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T mins(T &a,T1 b){if(b<a)a=b;return a;}

#define T  double

#define pt pair<T,T>

const T eps = 1e-6;

// (y-y1)(x2-x1)=(y2-y1)*(x-x1)
// y(x2-x1)+ x(y1-y2) = y1*(x2-x1)+x1*(y1-y2)






int sgn(const T &x){
	return x<-eps?-1:x>eps;
}

pt operator -(const pt &a,const pt &b){
	return {a.x-b.x,a.y-b.y};
}
pt operator *(const pt &a,T b){
	return {a.x*b,a.y*b};
}
T operator *(const pt &a,const pt &b){
	return a.x*b.y-b.x*a.y;
}
T operator %(const pt &a,const pt &b){
	return a.x*b.x+a.y*b.y;
}

T dis(const pt&a){
	return sqrt(a.x*a.x+a.y*a.y);
}

bool point_in_polygon(vector<pt>&p,pt O){
	int ret=0;
	int n=p.size();
	rep(i,0,n){
		pt u=p[i],v=p[(i+1)%n];
		if(sgn(u.y-v.y)<=0)swap(u,v);
		if(sgn(O.y-u.y)>0||sgn(O.y-v.y)<=0)continue;
		ret+=sgn((v-O)*(u-O))>0;
	}
	return ret&1;
}


T Area(const vector<pt>& fig) {
    T res = 0;
    for (unsigned i = 0; i < fig.size(); i++) {
        pt p = i ? fig[i - 1] : fig.back();
        pt q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return fabs(res) / 2;
}


// segment made by p1 and p2

T dist(pt A, pt B, pt E) { 
  
    pt AB=B-A; 
    pt BE=E-B; 
    pt AE=E-A; 
    T AB_BE, AB_AE; 
    AB_BE = AB%BE; 
    AB_AE = AB%AE;
    T reqAns = 0;   
    if (AB_BE > 0) { 
        return dis(E-B);
    } 
    else if (AB_AE < 0) { 
        return dis(E-A);
    } 
    else { 
        return  abs(AB*AE)/(dis(AB));
    } 
} 
  


bool check(pt cen,T r,vector<pt>&p){
	T dis=1e15;
	int m =sz(p);
	for(int i=0;i<m;i++){
		mins(dis,dist(p[i],p[(i+1)%m],cen));
		if(dis<=r || abs(dis-r)<eps)return 1;		
	}
	return 0;
	
}

const int N=1e6+5;

vector<pt>poly[N];
T area[N];


typedef long long ll;
typedef long unsigned long ull;
typedef double ld;



double rd() {
	string s;
	cin >> s;
	int k = s.size();
	int p = find(begin(s), end(s), '.') - begin(s);
	if (p == k) {
		ll x = 0;
		for (int i=0; i<k; i++) {
			x = 10*x + s[i] - 48;
		}
		return x;
	} else {
		ll x = 0, f = 0, g = 1;
		for (int i=0; i<p; i++) {
			x = 10*x + s[i] - 48;
		}
		for (int i=p+1; i<k; i++) {
			f = 10*f + s[i] - 48;
			g = 10*g;
		}
 
		return ld(x*g + f) / g;
	}
}



int solve(){
	T w,h;cin>>w>>h;
	int n;cin>>n;
	rep(i,0,n){
		int v;cin>>v;
		vector<pt>vec(v);
		rep(j,0,v){
			vec[j].x=rd();
			vec[j].y=rd();
		}
		area[i]=Area(vec);
		poly[i]=vec;
	}

	int q;cin>>q;
	//cout<<fixed<<setprecision(6);
	//rep(i,0,n){
	//	cout<<area[i]<<" ";
	//}cout<<endl;
	rep(k,0,q){
		T x,y,r;x=rd(),y=rd(),r=rd();
		pt cen={x,y};
		vector<int>temp;
		T ans=0;
		rep(i,0,n){
			if(point_in_polygon(poly[i],cen)){
				ans+=area[i];
				temp.pb(i);
			}
			else{
				if(check(cen,r,poly[i])){
					ans+=area[i];
					temp.pb(i);
				}
			}
		}
		cout<<ans<<" "<<sz(temp)<<" ";
		for(auto i:temp)cout<<i<<" ";cout<<endl;
	}
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
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    return 0;
}