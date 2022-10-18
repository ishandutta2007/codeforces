#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N = 1e5 + 11;


int main()
{
    string s;
    cin>>s;
    int kol4=0,kol7=0;
    for (int i=0; i<s.size(); i++)
        if (s[i]=='4') kol4++; else
        if (s[i]=='7') kol7++;
    if (kol4==0&&kol7==0) cout<<-1<<endl; else
    if (kol4>=kol7) cout<<4<<endl; else cout<<7<<endl;
}