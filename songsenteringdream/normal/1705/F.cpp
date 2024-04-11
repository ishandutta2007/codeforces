#include<iostream>
using namespace std;
int n,ansT,ansTF;string T,TF,str,ans;
int query(string s){
	int res;
	cout<<s<<endl;cin>>res;
	if(res==n) exit(0);
	return res;
}
int main(){
	cin>>n;
	ans=TF=T=string(n,'T');
	for(int i=1;i<n;i+=2) TF[i]='F';
	ansT=query(T);ansTF=query(TF);
	for(int l=0,r=n-1,v;l<=r;)
		if(l==r){str=T;str[l]='F';if(query(str)>ansT) ans[l]='F';else ans[l]='T';break;}
		else{
			str=T;str[l]=str[l+1]='F';
			if((v=query(str)-ansT)>0) ans[l]=ans[l+1]='F',l+=2;
			else if(v<0) ans[l]=ans[l+1]='T',l+=2;
			else if(r<l+2){
				str[l+1]='T';
				if(query(str)>ansT) ans[l]='F',ans[l+1]='T';
				else ans[l]='T',ans[l+1]='F';
				break;
			}
			else{
				str=TF;str[l]='F';str[l+1]='T';str[r]='F'+'T'-TF[r];
				if((v=query(str)-ansTF)==3) ans[l]='F',ans[l+1]='T',ans[r]=str[r];
				else if(v==1) ans[l]='F',ans[l+1]='T',ans[r]=TF[r];
				else if(v==-1) ans[l]='T',ans[l+1]='F',ans[r]=str[r];
				else ans[l]='T',ans[l+1]='F',ans[r]=TF[r];
				l+=2;--r;
			}
		}
	query(ans);
	return 0;
}