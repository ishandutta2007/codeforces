#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXV = 100100;

bool prime[MAXV];
vector <int> p1[10];
vector <int> p2[10][10];
vector <int> p3[10][10][10];
int nf[10][10][10][10];
int ns[10][10][10][10];

bool isprime (int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int numdig (int x)
{
    int temp = x;
    int ans = 0;
    while (temp > 0)
    {
        temp /= 10;
        ans++;
    }
    return ans;
}

void solve (string p)
{
    int arr[5][5];
    for (int i = 0; i < 5; i++)
        arr[0][i] = arr[i][0] = (int) (p[i] - '0');
    int ans = 0;
    for (int i = 0; i < p1[arr[0][1]].size(); i++)
    {
        int temp = p1[arr[0][1]][i];
        for (int j = 4; j >= 1; j--)
        {
            arr[1][j] = arr[j][1] = temp % 10;
            temp /= 10;
        }
        for (int j = 0; j < p2[arr[0][2]][arr[1][2]].size(); j++)
        {
            temp = p2[arr[0][2]][arr[1][2]][j];
            for (int k = 4; k >= 2; k--)
            {
                arr[2][k] = arr[k][2] = temp % 10;
                temp /= 10;
            }
            for (int k = 0; k < 10; k++)
                ans += ns[arr[0][3]][arr[1][3]][arr[2][3]][k] * nf[arr[0][4]][arr[1][4]][arr[2][4]][k];
        }
    }
    cout << ans << "\n";
}

int main()
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                for (int l = 0; l < 10; l++)
                    nf[i][j][k][l] = ns[i][j][k][l] = 0;
    prime[0] = prime[1] = false;
    for (int i = 2; i < 100000; i++)
    {
        prime[i] = isprime (i);
        if (prime[i])
        {
            p1[i/10000].push_back (i % 10000);
            p2[i/10000][(i/1000)%10].push_back (i % 1000);
            p3[i/10000][(i/1000)%10][(i/100)%10].push_back (i % 100);
            nf[i/10000][(i/1000)%10][(i/100)%10][(i/10)%10]++;
            ns[i/10000][(i/1000)%10][(i/100)%10][i%10]++;
        }
    }
    int t; cin >> t;
    for (int test = 0; test < t; test++)
    {
        string p; cin >> p;
        if (p.length() == 5)
        {
            solve (p);
        }
        else
        {
            int ans = 0;
            int arr[4][4];
            for (int i = 0; i < p.length(); i++)
                arr[i][0] = arr[0][i] = (int) (p[i] - '0');
            int exp = (p.length() * (p.length() - 1)) / 2;
            int pow = 1;
            for (int i = 0; i < exp; i++)
                pow *= 10;
            for (int i = 0; i < pow; i++)
            {
                int temp = i;
                for (int j = 1; j < p.length(); j++)
                    for (int k = j; k < p.length(); k++)
                    {
                        arr[j][k] = arr[k][j] = temp % 10;
                        temp /= 10;
                    }
                /*for (int j = 0; j < p.length(); j++)
                {
                    for (int k = 0; k < p.length(); k++)
                        cout << arr[j][k];
                    cout << "\n";
                }*/
                bool check = true;
                for (int j = 1; j < p.length(); j++)
                {
                    int x = 0;
                    for (int k = 0; k < p.length(); k++)
                        x = 10 * x + arr[j][k];
                    if (!prime[x])
                        check = false;
                }
                if (check)
                {
                    ans++;
                    //cout << arr[1][1] << "\n";
                }
            }
            cout << ans << "\n";
        }
    }
    //system ("Pause");
    return 0;
}