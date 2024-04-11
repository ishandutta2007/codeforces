#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,N) for(int i=n;i<=N;i++)
int a,b,c,d;
char x;
int main(){
	cin>>a>>x>>b;
	if(a==0){
		if(b==0)cout<<0<<endl;
		else cout<<70-b<<endl;
	}
	else if(a==1){
		if(b==10)cout<<0<<endl;
		else if(b<10) cout<<10-b<<endl;
		else cout<<80-b<<endl;
	}
	else if(a==2){
		if(b==20)cout<<0<<endl;
		else if(b<20) cout<<20-b<<endl;
		else cout<<90-b<<endl;
	}
	else if(a==3){
		if(b==30)cout<<0<<endl;
		else if(b<30) cout<<30-b<<endl;
		else cout<<100-b<<endl;
	}
	else if(a==4){
		if(b==40)cout<<0<<endl;
		else if(b<40) cout<<40-b<<endl;
		else cout<<110-b<<endl;
	}
	else if(a==5){
		if(b==50)cout<<0<<endl;
		else if(b<50) cout<<50-b<<endl;
		else cout<<301-b<<endl;
	}
	else if(a==6){
		cout<<241-b<<endl;
	}
	else if(a==7){
		cout<<181-b<<endl;
	}
	else if(a==8){
		cout<<121-b<<endl;
	}
	else if(a==9){
		cout<<61-b<<endl;
	}
	else if(a==10){
		if(b==1)cout<<0<<endl;
		else if(b<1) cout<<1-b<<endl;
		else cout<<71-b<<endl;
	}
	else if(a==11){
		if(b==11)cout<<0<<endl;
		else if(b<11) cout<<11-b<<endl;
		else cout<<81-b<<endl;
	}
	else if(a==12){
		if(b==21)cout<<0<<endl;
		else if(b<21) cout<<21-b<<endl;
		else cout<<91-b<<endl;
	}
	else if(a==13){
		if(b==31)cout<<0<<endl;
		else if(b<31) cout<<31-b<<endl;
		else cout<<101-b<<endl;
	}
	else if(a==14){
		if(b==41)cout<<0<<endl;
		else if(b<41) cout<<41-b<<endl;
		else cout<<111-b<<endl;
	}
	else if(a==15){
		if(b==51)cout<<0<<endl;
		else if(b<51) cout<<51-b<<endl;
		else cout<<302-b<<endl;
	}
	else if(a==16){
		cout<<242-b<<endl;
	}
	else if(a==17){
		cout<<182-b<<endl;
	}
	else if(a==18){
		cout<<122-b<<endl;
	}
	else if(a==19){
		cout<<62-b<<endl;
	}
	else if(a==20){
		if(b==2)cout<<0<<endl;
		else if(b<2) cout<<2-b<<endl;
		else cout<<72-b<<endl;
	}
	else if(a==21){
		if(b==12)cout<<0<<endl;
		else if(b<12) cout<<12-b<<endl;
		else cout<<82-b<<endl;
	}
	else if(a==22){
		if(b==22)cout<<0<<endl;
		else if(b<22) cout<<22-b<<endl;
		else cout<<92-b<<endl;
	}
	else if(a==23){
		if(b==32)cout<<0<<endl;
		else if(b<32) cout<<32-b<<endl;
		else cout<<60-b<<endl;
	}
	return 0;
}