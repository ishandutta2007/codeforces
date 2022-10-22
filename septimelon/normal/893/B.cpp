#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int maxd=0; int lastd=0; int osnd=0; int k=0;
    while (osnd<=n)
    {
        lastd=lastd*2+1;
        k++;
        osnd=lastd;
        for (int i=1; i<k; i++)
            osnd*=2;
        if (n%osnd==0&&osnd>maxd)
            maxd=osnd;
    }
    cout << maxd;
    return 0;
}