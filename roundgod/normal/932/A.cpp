#include<bits/stdc++.h>
#define MAXN 3005
#define F first
#define S second
#define MOD 1000000007
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN];
string S;
int main()
{
	cin>>S;
	string str=S;
	reverse(str.begin(),str.end());
	S+=str;
	cout<<S<<endl;
	return 0;
}