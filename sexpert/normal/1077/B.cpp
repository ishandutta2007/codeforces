#include <bits/stdc++.h>
using namespace std;

const int MAXN = 110;

int main()
{
    int n, A[MAXN];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int turns = 0;
    bool done = false;
    while(!done)
    {
        for(int i = 1; i < n - 1; i++)
        {
            if(A[i] == 0 && A[i - 1] == 1 && A[i + 1] == 1)
            {
                turns++;
                A[i + 1] = 0;
                break;
            }
            if(i == n - 2)
                done = true;
        }
    }
    cout << turns << endl;
}