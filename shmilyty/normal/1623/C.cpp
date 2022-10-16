#include<bits/stdc++.h>
using namespace std;
#define int long long
int t;
const int Size=200010;
int a[Size],b[Size],sol[Size];
int n[Size];

bool check(int seg,int se){
	bool res=true;
	for(int j=0;j<n[se];j++) b[j]=a[j];
	for(int j=n[se]-1;j>=0;j--){
		if (b[j]<seg){
			res = false;
			return res;
		}
		
		if (j>1){
			int u=min((b[j]-seg)/3,a[j]/3);
			b[j-1]=b[j-1]+u;
			b[j-2]=b[j-2]+2*u;
		}
		
	}
	return res;
}

void explore(int minn, int maxx, int se){
	
	if (minn==maxx){
		if (check(minn,se))
		sol[se]=minn;
		else
		sol[se]=-minn;
	} 
	else{
		
	int mids=(minn+maxx)/2;
	bool mres=check(mids,se);
	if (mres){
		if(check(mids+1,se)){
			explore(mids+1,maxx,se);
		}
		else{
			sol[se]=mids;
		}
		
	}
	else{
		explore(minn,mids-1,se);
	}
	}
	
}

void test(int se){
	
	cin >> n[se];
	
	for(int i=0;i<n[se];i++){
		cin >> a[i];
	}	
	//a[n]=0;
	//a[n+1]=0;
	int mi=a[0], sum=0;
	for(int i=0;i<n[se];i++){
		mi=min(mi,a[i]);
		sum+=a[i];
	}
	int ave=(sum+n[se]-1)/n[se];
	
	explore(mi,ave,se);
	
}

signed main(){
	cin >> t;
	for(int i=0;i<t;i++){
		test(i);
	}
	for (int i=0;i<t;i++){
		cout << sol[i]<<endl;
	}
	
	return 0;
}