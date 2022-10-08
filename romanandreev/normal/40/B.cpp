#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<ctime>
using namespace std;
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define y1 gfdsgfdsg

int main(){
    int n,m,k;
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    cin>>n>>m>>k;
    int t=1;
    while (n>0 && m>0){
        if (t==k){
            if (n==1 && m==1) cout<<1<<endl; else
            if (n==1) cout<<(m+1)/2; else
            if (m==1) cout<<(n+1)/2; else
            cout<<(n+m)-2<<endl;
            return 0;
        }
        t++;
        n-=2;
        m-=2;
    }
    cout<<0<<endl;
	return 0;
}