#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef __int64 ll;
char s[120];
int pos1=0,pos2=0,pose=0,b=0;
bool check(int pos){
    int len=strlen(s);
    bool flag=1;
    for(int i=pos;i<pose;i++){
        if(s[i]!='0') flag=0;
    }
    return flag;
}
int main(){
    cin>>s;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        if(s[i]=='.') pos1=i;
        if(s[i]=='e') pose=i;
        if(i>pose&&pose!=0) b=b*10+s[i]-'0';
    }
    pos2=pos1+b+1;
    bool front=1;
    for(int i=0;i<pose;i++){
        if(i<pos2){
            if(i==pos1) continue;
            cout<<s[i];
        }
        if(i>=pos2){
            if(check(pos2)){
                return 0;
            }
            if(i==pos2){
                cout<<".";
            }
            if(i>=pos2){
                cout<<s[i];
            }
        }
    }
    for(int i=pose;i<pos2;i++) cout<<"0";
    return 0;
}