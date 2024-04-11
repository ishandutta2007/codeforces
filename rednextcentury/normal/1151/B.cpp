#include<bits/stdc++.h>
using namespace std;
int mn[1000];
int mx[1000];
int a[501][501];
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
        int cur=0;
	vector<int> vec;
	for (int i=1;i<=n;i++) {
		mn[i]=1;
		mx[i]=1;
		for (int j=1;j<=m;j++) {
			cin>>a[i][j];
			if (a[i][mx[i]]<a[i][j])mx[i]=j;
			if (a[i][mn[i]]>a[i][j])mn[i]=j;
		}
		cur^=a[i][mx[i]];
		vec.push_back(mx[i]);
	}
	if (cur==0) {
		bool ok=0;
		for (int i=1;i<=n;i++) {
			if (a[i][mx[i]]!=a[i][mn[i]] && !ok){
				ok=1;			
				vec[i-1]=mn[i];
			}		
		}
                if (!ok){
			cout<<"NIE"<<endl;
			return 0;		
		}	
	}
	cout<<"TAK"<<endl;
	for (auto x:vec)cout<<x<<" ";
	
}