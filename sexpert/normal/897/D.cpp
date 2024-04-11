#include <iostream>

using namespace std;

int main()
{
    int n, m, c;
    cin >> n >> m >> c;
    int sheets[n] = {};
    int treshold = c/2;
    bool done = false;
    int l;
    int lowEndIndex = 0, highEndIndex = n - 1;
    while(!done)
    {
        cin >> l;
        if(l <= treshold)
        {
            for(int i = 0; i <= lowEndIndex + 1; i++)
            {
                if(l < sheets[i] || sheets[i] == 0)
                {
                    sheets[i] = l;
                    cout << i + 1 << endl;
                    fflush(stdout);
                    if(i > lowEndIndex)
                        lowEndIndex = i;
                    break;
                }
            }
        }
        else
        {
            for(int i = n - 1; i >= highEndIndex - 1; i--)
            {
                if(l > sheets[i] || sheets[i] == 0)
                {
                    sheets[i] = l;
                    cout << i + 1 << endl;
                    fflush(stdout);
                    if(i < highEndIndex)
                        highEndIndex = i;
                    break;
                }
            }
        }
        done = true;
        for(int i = 0; i < n - 1; i++)
        {
            if(sheets[i + 1] < sheets[i] || sheets[i] == 0)
                done = false;
        }
    }
    return 0;
}