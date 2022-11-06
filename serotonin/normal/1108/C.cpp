#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz=1e6+5;

char s[sz];

int fnc(int n, char a, char b, char c)
{
    int ans=0;
    for(int i=0; i<n; i++) {
        if(i%3==0 && s[i]!=a) ans++;
        else if(i%3==1 && s[i]!=b) ans++;
        else if(i%3==2 && s[i]!=c) ans++;
    }
    return ans;
}

void printnow(int n, int f)
{
    char a,b,c;
    if(f==1) a='R',b='G',c='B';
    else if(f==2) a='R',b='B',c='G';
    else if(f==3) a='G',b='R',c='B';
    else if(f==4) a='G',b='B',c='R';
    else if(f==5) a='B',b='G',c='R';
    else a='B',b='R',c='G';

    for(int i=0; i<n; i++) {
        if(i%3==0) printf("%c", a);
        else if(i%3==1) printf("%c", b);
        else printf("%c", c);
    }
    puts("");
}

int main()
{
    int i,j,n;
    cin >> n;
    scanf("%s", s);
    int x,ans=sz,decider;
    x=fnc(n,'R','G','B');
    if(x<ans) decider=1,ans=x;
    x=fnc(n,'R','B','G');
    if(x<ans) decider=2,ans=x;
    x=fnc(n,'G','R','B');
    if(x<ans) decider=3,ans=x;
    x=fnc(n,'G','B','R');
    if(x<ans) decider=4,ans=x;
    x=fnc(n,'B','G','R');
    if(x<ans) decider=5,ans=x;
    x=fnc(n,'B','R','G');
    if(x<ans) decider=6,ans=x;

    printf("%d\n", ans);
    printnow(n,decider);
}