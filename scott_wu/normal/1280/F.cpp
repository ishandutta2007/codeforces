#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 110;

int N, K;
int goal[2][MAXN];
int grid[2][MAXN];
int cx, cy;
vector <char> ans;

void gr()
{
    swap (grid[cx][cy], grid[cx][cy+1]);
    ans.push_back('r');
    cy++;
}

void gl()
{
    swap (grid[cx][cy], grid[cx][cy-1]);
    ans.push_back('l');
    cy--;
}

void gu()
{
    swap (grid[cx][cy], grid[cx-1][cy]);
    ans.push_back('u');
    cx--;
}

void gd()
{
    swap (grid[cx][cy], grid[cx+1][cy]);
    ans.push_back('d');
    cx++;
}

void gcol (int x)
{
    while (cy < x)
    {
        gr();
    }
    while (cy > x)
    {
        gl();
    }
}

void grow (int x)
{
    while (cx < x)
        gd();
    while (cx > x)
        gu();
}

void left_loop()
{
    // be at q
    int cs = ans.size();
    gcol (0);
    gu ();
    gcol (K);
    gd ();
    while (ans.size() > cs) ans.pop_back();
    ans.push_back('L');
}

void left_rev()
{
    int cs = ans.size();
    gu ();
    gcol (0);
    gd ();
    gcol (K);
    while (ans.size() > cs) ans.pop_back();
    ans.push_back('M');
}

void right_loop()
{
    int cs = ans.size();
    // be at q
    gcol (N - 1);
    gu ();
    gcol (K);
    gd ();
    while (ans.size() > cs) ans.pop_back();
    ans.push_back('R');
}

void right_rev()
{
    int cs = ans.size();
    gu ();
    gcol (N - 1);
    gd ();
    gcol (K);
    while (ans.size() > cs) ans.pop_back();
    ans.push_back('S');
}

void swappy()
{
    // swap[0][K] and [1][K-1]
    right_loop();
    left_loop();
    right_rev();
    left_rev();
    right_loop();
    left_loop();
}

int ntt;

void swappyr()
{
    // swap[0][K] and [1][K-1]
    ntt++;
    if (ntt % 2 == 0) {
        left_loop();
        right_loop();
        left_rev();
        right_rev();
        left_loop();
        right_loop();
    }
    else
    {
        left_rev();
        right_loop();
        left_loop();
        right_rev();
        left_rev();
        right_loop();
    }
}

bool is_left (int partner)
{
    return partner == (K + 1) || ((partner % N) >= 1 && (partner % N) <= K);
}

void gogo()
{
    cin >> K;
    N = 2 * K + 1;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            string s; cin >> s;
            if (s[0] == 'E')
            {
                grid[i][j] = 0;
                cx = i;
                cy = j;
            }
            else
            {
                if (s.length() == 1) grid[i][j] = s[0] - '0';
                else grid[i][j] = 10 * (s[0] - '0') + (s[1] - '0');
            }
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < N; j++)
        {
            goal[i][j] = i * N + j + 1;
        }
    }
    goal[1][N-1] = 0;

    ans.clear();
    gcol (K);
    grow (1);

    int nt = 0;
    while (nt < N + 3)
    {
        int partner = grid[0][K];
        if (is_left(partner))
        {
            // cool
            nt++;
            left_loop();
            continue;
        }
        else
        {
            nt = 0;
            while (!is_left(partner))
            {
                right_loop();
                partner = grid[0][K];
            }
        }
    }

    vector <int> v;
    for (int i = K; i >= 0; i--)
        v.push_back(goal[0][i]);
    for (int i = 0; i < K; i++)
        v.push_back(goal[1][i]);

    while (grid[0][K] != v[0])
        left_loop();
    for (int i = 1; i < v.size(); i++)
    {
        int cval = v[i];
        while (grid[0][K] != cval)
            left_loop();
        while (grid[1][K-1] != v[i-1])
            swappy();
    }
    while (grid[0][K] != v[0])
        left_loop();

    v.clear();
    for (int i = K; i < N; i++)
        v.push_back(goal[0][i]);
    for (int i = N - 1; i >= K; i--)
    {
        if (goal[1][i])
        v.push_back(goal[1][i]);
    }

    while (grid[0][K] != v[0])
        right_loop();
    for (int i = 1; i < v.size(); i++)
    {
        int cval = v[i];
        while (grid[0][K] != cval)
            right_loop();
        while (grid[1][K+1] != v[i-1])
            swappyr();
    }
    while (grid[0][K] != v[0])
        right_loop();

    gcol (N - 1);

    bool bad = false;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < N; j++)
        {
            if (goal[i][j] != grid[i][j])
                bad = true;
        }
    if (bad) cout << "SURGERY FAILED\n";
    else
    {
        cout << "SURGERY COMPLETE\n";
        for (char c : ans)
            cout << c;
        cout << "\n";
        cout << "L ";
        for (int i = 0; i < K; i++)
            cout << 'l';
        cout << 'u';
        for (int i = 0; i < K; i++)
            cout << 'r';
        cout << 'd';
        cout << "\n";
        cout << "M ";
        cout << 'u';
        for (int i = 0; i < K; i++)
            cout << 'l';
        cout << 'd';
        for (int i = 0; i < K; i++)
            cout << 'r';
        cout << "\n";
        cout << "R ";
        for (int i = 0; i < K; i++)
            cout << 'r';
        cout << 'u';
        for (int i = 0; i < K; i++)
            cout << 'l';
        cout << 'd';
        cout << "\n";
        cout << "S ";
        cout << 'u';
        for (int i = 0; i < K; i++)
            cout << 'r';
        cout << 'd';
        for (int i = 0; i < K; i++)
            cout << 'l';
        cout << "\n";
        cout << "DONE\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}