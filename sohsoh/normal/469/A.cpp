

    #include<bits/stdc++.h>
    using namespace std;
    int a,b,c,d;
    set<int>st;
    int main(){
    	cin>>a>>b;
    	for(int i=0;i<b;i++){
    		cin>>d;
    		st.insert(d);}
    	cin>>c;
    	for(int i=0;i<c;i++){
    		cin>>d;
    		st.insert(d);}
    	if(st.size()==a)cout<<"I become the guy.";
    	else cout<<"Oh, my keyboard!";
    	
    	return 0;
    }