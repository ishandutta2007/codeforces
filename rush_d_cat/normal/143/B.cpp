#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
char s[202];int minu = 0, n, dot;
vector<char> v;
void rush() {
    if(s[1] == '-') minu = 1;
    else return;

    for(int i=1;i<=n-1;i++) {
        s[i] = s[i+1];
    }
    n --; dot --;
}
int main()
{
    scanf("%s", s+1);
    n = strlen(s+1);
    dot = n+1;
    for(int i=1;i<=n;i++)
    {
        if(s[i] == '.') dot = i;
    }
    rush();
    v.push_back(s[1]);
    for(int i=2;i<=min(n, dot+2);i++) {
        if((dot - i) % 3 == 0 && dot != i) {
            v.push_back(',');
        }
        v.push_back(s[i]);
    }
    if(dot == n-1) v.push_back('0');
    if(dot == n+1) v.push_back('.'), v.push_back('0'), v.push_back('0');
    if(minu) printf("(");
    printf("$");
    for(int i=0;i<v.size();i++) {
        printf("%c", v[i]);   
    }
    if(minu) printf(")");
}