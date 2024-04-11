#include<iostream>
using namespace std;
int T;string s;int cnt;
inline void slv(int rw,int cl,int dir){
	if(++cnt>130) return;
	cout<<rw<<" "<<cl<<endl;cout.flush();
	cin>>s;
	if(s=="Done") return;
	if(s=="Up-Left"||s=="Up-Right"||s=="Up") slv(rw-1,cl,dir);
	else if(s=="Down-Left"||s=="Down-Right"||s=="Down") if(cl^1) slv(rw,1,1);else slv(rw,8,-1);
	else if(cl+dir>8||!(cl+dir)) slv(rw-1,cl,-dir);
	else slv(rw,cl+dir,dir);
}
int main(){
	for(cin>>T;T--;){
		cout<<"8 8\n";cout.flush();cin>>s;if(s!="Done") cnt=0,slv(8,1,1);
	}
	return 0;
}