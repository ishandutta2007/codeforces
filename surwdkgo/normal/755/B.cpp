#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

char tmp[1010];

void Solve()
{
    vector<string> a, b;
    int na, nb;
    scanf("%d%d", &na, &nb);
    for (int i=0; i<na; i++)
    {
        scanf("%s", tmp);
        a.push_back(tmp);
    }
    for (int i=0; i<nb; i++)
    {
        scanf("%s", tmp);
        b.push_back(tmp);
    }
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    int sc = 0;
    for (int i=0, j=0; i<na;)
    {
        if (j >= nb) break;
        if (a[i] == b[j])
        {
            sc++;
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    int ac = (na - sc) + (sc+1)/2;
    int bc = (nb - sc) + sc/2;
    printf("%s\n", ac >= bc+1 ? "YES" : "NO");
    return;
}

int main()
{
    int cas = 1;
    for (int i = 0; i < cas; i++)
    {
        Solve();
    }
    return 0;
}