#include <bits/stdc++.h>
using namespace std;
int T;
long long n;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		long long haha1=n%3;
		long long haha2=(n-haha1)/3;
		long long haha3=(n-haha1)/3;
		if(haha1==1){
			haha2++;
		}else if(haha1==2){
			haha3++;
		}
		cout<<haha2<<" "<<haha3<<endl;
	}
}