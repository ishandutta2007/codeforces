#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
//#define int long long
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

int c[100010],val1[20],val2[20],val3[20];

signed main()
{
	ios::sync_with_stdio(false);
	int n,a1,a2,a3,x1,x2,x3;
	cin>>n;
	int p=n,k=-1;
	while(p!=0){
		p/=2;k++;
	}
	cout<<"AND 1 2\n";fflush(stdout);
	cin>>a1;
	cout<<"AND 2 3\n";fflush(stdout);
	cin>>a2;
	cout<<"AND 1 3\n";fflush(stdout);
	cin>>a3;
	cout<<"XOR 1 2\n";fflush(stdout);
	cin>>x1;
	cout<<"XOR 2 3\n";fflush(stdout);
	cin>>x2;
	x3=x1^x2;
	for(int i=0;i<k;i++) val1[i]=val2[i]=val3[i]=-1;
	for(int i=0;i<k;i++){
		if((a1&(1<<i))>0) val1[i]=1,val2[i]=1;
		if((a1&(1<<i))==0&&(x1&(1<<i))==0) val1[i]=0,val2[i]=0;
	}
	for(int i=0;i<k;i++){
		if((a3&(1<<i))>0) val1[i]=1,val3[i]=1;
		if((a3&(1<<i))==0&&(x3&(1<<i))==0) val1[i]=0,val3[i]=0;
	}
	for(int i=0;i<k;i++){
		if((a2&(1<<i))>0) val2[i]=1,val3[i]=1;
		if((a2&(1<<i))==0&&(x2&(1<<i))==0) val2[i]=0,val3[i]=0;
	}
	for(int i=0;i<k;i++){
		if((x1&(1<<i))>0){
			if(val1[i]==-1) val1[i]=val2[i]^1;
			else if(val2[i]==-1) val2[i]=val1[i]^1;
		}
	}
	for(int i=0;i<k;i++){
		if((x3&(1<<i))>0){
			if(val1[i]==-1) val1[i]=val3[i]^1;
			else if(val3[i]==-1) val3[i]=val1[i]^1;
		}
	}
	for(int i=0;i<k;i++){
		if((x2&(1<<i))>0){
			if(val2[i]==-1) val2[i]=val3[i]^1;
			else if(val3[i]==-1) val3[i]=val2[i]^1;
		} 
	}
	for(int i=0;i<k;i++){
		c[1]+=val1[i]*(1<<i);
		c[2]+=val2[i]*(1<<i);
		c[3]+=val3[i]*(1<<i);
	}
	for(int i=4;i<=n;i++){
		cout<<"XOR "<<i-1<<" "<<i<<'\n';fflush(stdout);
		int x;cin>>x;
		c[i]=c[i-1]^x;
	}
	cout<<"! ";
	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	cout<<'\n';fflush(stdout);
	return 0;
}