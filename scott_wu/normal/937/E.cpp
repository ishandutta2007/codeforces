#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;
const int MAXN = 2100;

int N;
string S, T;
int scount[MAXN];
char cv[MAXN];
char mcv[MAXN];
vector <int> v;

void op (int x)
{
    v.push_back(x);
    for (int i = 0; i < x; i++)
        mcv[i] = cv[N-1-i];
    for (int i = x; i < N; i++)
        mcv[i] = cv[i-x];
    for (int i = 0; i < N; i++)
        cv[i] = mcv[i];
}

int main()
{
    cin >> N >> S >> T;
    for (int i = 0; i < 26; i++)
        scount[i] = 0;
    for (int i = 0; i < N; i++)
    {
        scount[S[i]-'a']++;
        scount[T[i]-'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (scount[i] != 0)
        {
            cout << "-1\n";
            return 0;
        }
    }

    for (int i = 0; i < N; i++)
        cv[i] = S[i];

    int sstart = N / 2;
    int send = sstart;
    for (int i = 0; i < N; i++)
    {
        if (cv[i] == T[sstart])
        {
            op (N - 1 - i);
            op (1);
            break;
        }
    }

    int dir = -1;
    int sz = 1;
    while (sz < N)
    {
        if (dir == -1)
        {
            for (int i = sz; i < N; i++)
                if (cv[i] == T[sstart-1])
                {
                    op (N - i);
                    op (i - sz);
                    op (sz+1);
                    break;
                }
            sstart--;
        }
        else
        {
            for (int i = sz; i < N; i++)
                if (cv[i] == T[send+1])
                {
                    op (N - i);
                    op (i - sz);
                    op (sz+1);
                    break;
                }
            send++;
        }
        dir = -dir;
        sz++;
    }
    if (N % 2 == 0)
        op (N);

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << "\n";
    /*for (int i = 0; i < N; i++)
        cout << cv[i];
    cout << "\n";*/
}