#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<cstdlib>
#define ll long long
#define pb push_back
#define len length()
#define si size()
using namespace std;

int n;
string a[101];
int col[10001],row[10001];int tot=0;
int p[101],q[101];bool v[101],m[101];
bool check1(){
    for(int i=0;i<n;i++)
       if(!col[i]) return false;
    return true;
}
bool check2(){
    for(int j=0;j<n;j++)
       if(!row[j]) return false;
    return true;
}

bool cmp(int x,int y){return col[x]<col[y]||(col[x]==col[y]&&row[x]<row[y]);}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<n;j++)
           if(a[i][j]!='E')
           {
            col[i]=1;row[j]=1;
           } 
    }
    
    if(check1()){
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
               if(row[j]&&a[i][j]!='E') {cout<<i+1<<" "<<j+1<<endl;break;}
    }
    else if(check2()){
        for(int j=0;j<n;j++)
           for(int i=0;i<n;i++)
              if(col[i]&&a[i][j]!='E'){cout<<i+1<<" "<<j+1<<endl;break;}
    }
    else cout<<-1<<endl;
    return 0;
}