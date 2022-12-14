#include <bits/stdc++.h>
#define ll long long
using namespace std;
char op[3000];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    for (char i='a';i<='z';i++)
        op[i]='4';
    for (char i='A';i<='Z';i++)
        op[i]='4';
    op['p']='q';
    op['q']='p';
    op['b']='d';
    op['d']='b';
    op['A']='A';
    op['H']='H';
    op['I']='I';
    op['M']='M';
    op['O']='O';
    op['o']='o';
    op['T']='T';
    op['U']='U';
    op['V']='V';
    op['v']='v';
    op['W']='W';
    op['w']='w';
    op['X']='X';
    op['Y']='Y';
    op['x']='x';
    for (int i=0;i<s.size();i++)
    {
        if (op[s[i]]!=s[s.size()-1-i]){
            cout<<"NIE"<<endl;
            return 0;
        }
    }
    cout<<"TAK"<<endl;
}