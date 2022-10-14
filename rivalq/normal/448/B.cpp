//https://codeforces.com/contest/448/problem/B
//undefined
#include<bits/stdc++.h>
using namespace std;
#define lop(i,n) for(int i=0;i<n;i++)
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s1,s2,s3="";
    cin>>s1>>s2;
    int n1=s1.length(),n2=s2.length();
    if(n1==n2){
        sort(s2.begin(),s2.end());sort(s1.begin(),s1.end());
        if(s1==s2) cout<<"array\n";else cout<<"need tree\n";
    }
    else {
        int j=0;
        lop(i,n1) {
            if(s2[j]==s1[i]) {s3+=s1[i];j++;}
            }
            if(s3.length()==n2) {
                cout<<"automaton\n";
            }
            else {
               sort(s2.begin(),s2.end());sort(s1.begin(),s1.end());
               int j=0;s3="";
               lop(i,n1) {
                    if(s2[j]==s1[i]) {s3+=s1[i];j++;}
                         }
                    if(s3.length()==n2) {
                        cout<<"both\n";
                    }
                    else cout<<"need tree\n";
            }
            

    }
}