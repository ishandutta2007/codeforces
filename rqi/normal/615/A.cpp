#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;
int n,m, a,bulbs[100];
 int k;

int main() {
 	cin>>n>>m;
 	F0R(i,n){
 		cin>>k;
 		
 		F0R(j,k){
 			cin>>a;
	 		bulbs[a-1]=1;
 		}
 	}
 	F0R(i,m) {
 		if(bulbs[i]==0) {
 			cout<<"NO";
 			return 0;
 		}
 	}
 	cout<< "YES";
 	return 0;
}