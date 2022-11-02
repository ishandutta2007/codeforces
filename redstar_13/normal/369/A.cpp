#include<bits/stdc++.h>



using namespace std;



int main(){

//	freopen("in.txt","r",stdin);

	

	int n,m,k,ans=0,a;

	cin>>n>>m>>k;

	for(int i=1;i<=n;i++) { 

		scanf("%d",&a);	

		if(a==1) { if(m) m--; else ans++; }

		if(a==2) { if(k) k--; else if(m) m--; else ans++; }

	}

	printf("%d",ans);

	return 0;

}