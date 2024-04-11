#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
#define int long long
using namespace __gnu_pbds;
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

inline int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

inline void exgcd(int a,int b,int &r,int &u)
{
	if(b==0) return;
	int q=a/b;
	int prer=r,preu=u;
	r=preu;u=prer-q*preu;
	exgcd(b,a%b,r,u);
}

inline int inverse(int x,int mod)
{
	int r,u;
	exgcd(x,mod,r=1,u=0);
	return r;
}

inline int getint()
{
	char ch=getchar();
	int r=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		r=r*10+ch-'0';
		ch=getchar();
	}
	return r;
}

int n,m,k,a[1000010],b[1000010],pos[1000010];

signed main()
{
	n=getint(),m=getint(),k=getint();
	for(int i=0;i<n;i++) a[i]=getint();
	for(int i=0;i<n;i++) pos[a[i]]=-1;
	for(int i=0;i<m;i++) b[i]=getint(),pos[b[i]]=i;
	int val=gcd(n,m),rev=inverse(n/val,m/val);
	vector<int> v;
	for(int i=0;i<n;i++){
		if(pos[a[i]]!=-1){
			if(i%val==pos[a[i]]%val){
				int b=(((pos[a[i]]-i)/val)+m/val)%(m/val);
				int t=((rev*b)%(m/val)+(m/val))%(m/val);
				v.push_back(i+t*n);
			}
		}
	}
	v.push_back(n/val*m);
	sort(v.begin(),v.end());
	int tot=n/val*m-(v.size()-1);
	int round=k/tot,rem=k%tot,pre=-1,now=0;
	if(rem==0){
		int now=n/val*m;
		for(int i=v.size()-1;i>=0;i--){
			if(v[i]!=now) break;
			now--;
		}
		cout<<(round-1)*n/val*m+now+1<<endl;
		return 0;
	}
	for(int i=0;i<v.size();i++){
		if(now+v[i]-pre-1>=rem){
			cout<<round*n/val*m+pre+rem-now+1<<endl;
			break;
		}
		now+=v[i]-pre-1;
		pre=v[i];
	}
	return 0;
}