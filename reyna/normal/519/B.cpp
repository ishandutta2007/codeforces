//In the name of God
#include <bits/stdc++.h>
using namespace std;

#define Mp make_pair
#define For(i,j,n) for(int i=(j);i<((int)n);++i)
#define Pb push_back
#define Err(x) cerr << #x << " = " << (x) << endl;
#define Get(a) scanf("%d",&a)
#define Put(a) printf("%d\n",a);
#define F first
#define S second


typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int Maxn = 1e6 + 1e3;
map<int,int> one;
map<int,int> two;
map<int,int> three;
map<int,int> Bool;
int arr[Maxn];
int main(){
	int n;
	cin >> n;
	For(i,0,n){
		Get(arr[i]);
		one[arr[i]]++;
	}
	For(i,0,n-1){
		int now;
		Get(now);
		two[now]++;
	}
	For(i,0,n-2){
		int now;
		Get(now);
		three[now]++;
	}
	int f = 0,s = 0;
	For(i,0,n){
		if(one[arr[i]] != two[arr[i]]){
			if(!Bool[arr[i]]){
				f = arr[i];
				Bool[arr[i]] = 1;
			}
		}
	}
	For(i,0,n){
		if(two[arr[i]] != three[arr[i]]){
			if(Bool[arr[i]] != 2){
				s = arr[i];
				Bool[arr[i]] = 2;
			}
		}
	}
	Put(f);
	Put(s);
}