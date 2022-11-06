#include <bits/stdc++.h>
using namespace std;

int a[101], n = 1;
void input()
{
    while(true)
    {
        char ch = getchar();
        if(ch == ',') ++n;
        else if(ch >= '0' && ch <= '9')
            a[n] = a[n] * 10 + ch - '0';
        else return;
    }
}

int main()
{
    bool book = false;
	input();
    sort(a+1, a+1+n);
    for(int i=1;i<=n;i++)
    {
        int cur = i;
        while(a[cur+1] - a[cur] == 1 || a[cur+1] - a[cur] == 0) ++cur;
        if(book) printf(",");
        if(a[cur] == a[i]) printf("%d", a[i]);
        else printf("%d-%d", a[i], a[cur]);
		book = true;
		i = cur;
    }
    printf("\n");
    return 0;
}