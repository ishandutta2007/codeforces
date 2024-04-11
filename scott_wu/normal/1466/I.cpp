#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 210;

int N, B;
string lhi[MAXN];
bool bad[MAXN];

string m1 (string s)
{
    int lv = s.length() - 1;
    while (lv >= 0)
    {
        if (s[lv] == '1') break;
        else lv--;
    }
    if (lv == -1) return s;

    s[lv] = '0';
    for (int i = lv + 1; i < s.length(); i++)
        s[i] = '1';
    return s;
}

bool ask (int ind, string s)
{
    int lv = s.length() - 1;
    while (lv >= 0)
    {
        if (s[lv] == '1') break;
        else lv--;
    }
    if (lv == -1) return true;
    s[lv] = '0';
    for (int i = lv + 1; i < s.length(); i++)
        s[i] = '1';

    cout << ind + 1 << " " << s << "\n";
    cout << flush;

    string res; cin >> res;
    if (res[0] == 'y') return true;
    return false;
}

void gogo()
{
    string vcur = "";
    for (int i = 0; i < B; i++)
        vcur += '0';
    int cbit = 0;

    string all1 = "";
    for (int i = 0; i < B; i++)
        all1 += '1';
    for (int i = 0; i < N; i++)
    {
        lhi[i] = all1;
    }

    while (true)
    {
        int bloc = 0;
        for (int i = 1; i < N; i++)
            if (lhi[i] > lhi[bloc])
                bloc = i;
        if (lhi[bloc] <= vcur) break;

        //cout << bloc << " " << vcur << endl;

        vcur[cbit] = '1';
        if (ask (bloc, vcur))
        {
            //cout << vcur << endl;
            if (cbit < (B - 1)) cbit++;
            while (true)
            {
                string vnext = vcur;
                int p = B - 1;
                while (vnext[p] == '0') p--;

                int nhas = p;
                while (nhas >= 0)
                {
                    if (vnext[nhas] == '1') nhas--;
                    else break;
                }
                if (nhas == -1)
                    break;

                vnext[nhas] = '1';
                for (int i = nhas + 1; i <= p; i++)
                    vnext[i] = '0';
                if (ask (bloc, vnext))
                {
                    vcur = vnext;
                    cbit = nhas + 1;
                }
                else
                {
                    lhi[bloc] = m1 (vnext);
                    break;
                }
            }
        }
        else
        {
            lhi[bloc] = m1 (vcur);
            //cout << vcur << endl;
            vcur[cbit] = '0';
            //cout << vcur << endl;
            if (cbit < B - 1) cbit++;
        }
    }
    cout << "0 " << vcur << "\n";
}

int main()
{
    cin >> N >> B;

    gogo();
}