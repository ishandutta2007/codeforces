#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100][100];
void change(int i,int j){
    a[i][j]++;
    if (a[i][j]==10)a[i][j]=1;
}
int main()
{
    ios_base::sync_with_stdio(  0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        for (int i=1;i<=9;i++)for (int j=1;j<=9;j++){
            char x;
            cin>>x;
            a[i][j]=x-'0';
        }
        change(1,1);
        change(5,2);
        change(9,3);
        change(2,4);
        change(4,5);
        change(6,7);
        change(3,9);
        change(7,6);
        change(8,8);
        for (int i=1;i<=9;i++){
            for (int j=1;j<=9;j++){
                cout<<a[i][j];
            }
            cout<<endl;
        }
    }
}