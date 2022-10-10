#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int perm[1000005];
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&perm[i]);
        perm[i]--;
    }
    vector<int> vist(n + 1);
    int parity = 0;
    for(int i = 0; i < n; i++)
    {
        if(vist[i] == 0)
        {
            int cycleLen = 0, curr = i;
            vist[i] = 1;
            while(cycleLen < 1000005)
            {
                curr = perm[curr];
                cycleLen++;
                if(curr == i) break;
                vist[curr] = 1;
            }
            if(!(cycleLen%2)) parity++;
        }
    }
    if(n % 2 == 1)
    {
        if(parity%2) cout << "Petr";
        else cout << "Um_nik";
    }
    else
    {
        if(parity%2) cout << "Um_nik";
        else cout << "Petr";
    }
}