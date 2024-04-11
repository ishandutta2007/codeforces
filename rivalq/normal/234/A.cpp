#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;string s;
    vector<string> v;
    ifstream in("input.txt");
    ofstream ou("output.txt");
    while (getline(in, s))
{
	if(s.size() > 0)
		v.push_back(s);
}
n=stoi(v[0]);
s=v[1];
    for(int i=0;i<n/2;i++){
        if(s[n/2+i]=='L'){
            ou <<n/2+i+1<<" "<<i+1<<endl;
        }
        else{
           ou<<i+1<<" "<<n/2+i+1<<endl;
        }
    }
}