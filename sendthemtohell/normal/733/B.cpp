#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin>>n;
	vector<int> left,right;
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		left.push_back(a);
		right.push_back(b);
	}
	ll L=0,R=0,maxL,maxR,nmaxL,nmaxR;
	for(int i=0;i<n;i++){
		L+=left[i];
		R+=right[i];
	}
	nmaxL=0;
	maxL=L-R;
	maxR=R-L;
	nmaxR=0;
	for(int i=0;i<n;i++){
		if(L-R+2*(right[i]-left[i]) > maxL){
			maxL=L-R+2*(right[i]-left[i]);
			nmaxL=i+1;
		}
		if(R-L+2*(left[i]-right[i]) > maxR){
			maxR=R-L+2*(left[i]-right[i]);
			nmaxR=i+1;
		}
	}
	if(maxR>maxL)
		cout<<nmaxR;
	else
		cout<<nmaxL;
	//if(n>10000){
		//cout<<"     "<<nmaxR<<"      "<<nmaxL<<"      "<<maxR<<"         "<<maxL<<"    "<<L-R<<"     "<<R-L;
	//}
	cout<<endl;
	return 0;
}