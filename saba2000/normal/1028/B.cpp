#include<bits/stdc++.h>
using namespace std;
main(){
    int n, m;
    cin >>n >> m;
    string s1,s2;
    for(int i = 1; i <= 2000; i++)
        s1 +='5';
    for(int i = 1; i <= 2000; i++)
        s2 +='4';
    s2[1999] = '5';
    cout<<s1<<" "<<s2<<endl;
}