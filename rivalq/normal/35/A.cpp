#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;string s;
    vector<string> v;
    ifstream in("input.txt");
    ofstream ou("output.txt");
    while (getline(in, s)){
	  if(s.size() > 0)
		v.push_back(s);
    }
    n=stoi(v[0]);
    int arr[3];
    arr[n-1]=1;
    for(int i=1;i<4;i++){
       s=v[i];
       arr[(s[0])-1-'0']=arr[s[2]-'0'-1]+arr[(s[0])-1-'0']-(arr[s[2]-'0'-1]=arr[(s[0])-1-'0']);
    }
    if(arr[0]==1) ou<<1<<endl;
    else if(arr[1]==1) ou<<2<<endl;
    else if(arr[2]==1) ou<<3<<endl;

   
}