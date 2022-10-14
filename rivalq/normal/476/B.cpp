#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{
	if (n==0||n==1)
	return 1;
	else 
	return n*fact(n-1);
}

int main() 
{   
	string c,d;
	cin>>c>>d;
	int l = c.length();
	int position=0;
	int un=0;
	int reach=0;
	for (int i = 0;i<l;i++){
		if(c[i]=='+'){
			position++;
		}
		else{
			position--;
		}}
		for (int j = 0;j<l;j++){
		if(d[j]=='+'){
			reach++;
		}
		else if(d[j]=='-'){
			reach--;
		}
		else{
			un++;
		}
		
	}
	int req= abs(reach-position);
	if (req>un){
		cout<<fixed;
		cout<<"0.000000000000";
		
	}
 
	else if((un-req)%2==0){
		cout<<fixed;
		cout<<setprecision(12)<<fact(un)/((fact(req +(un-req)/2)*fact((un-req)/2)*pow(2,un)));
	}
	else{
		cout<<"0.000000000000";
	}
	
	return 0;
}