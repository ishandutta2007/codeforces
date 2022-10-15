#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int N;

struct mset {
    int siz;
    int cnt[26];
};

mset zero_mset;

mset reads(void)
{
    char s[105];
    scanf("%s", s);
    mset ans = zero_mset;
    for (int i = 0; s[i]; i++) {
        ans.siz++; ans.cnt[s[i]-'a']++;
    }
    return ans;
}

void sendq(int l, int r)
{
    printf("? %d %d\n", l, r); fflush(stdout);
}

mset totals[105];

mset operator+(mset a, mset b)
{
    mset c;
    c.siz = a.siz + b.siz;
    for (int i = 0; i < 26; i++) c.cnt[i] = a.cnt[i] + b.cnt[i];
    return c;
}

mset operator-(mset a, mset b)
{
    mset c;
    c.siz = a.siz - b.siz;
    for (int i = 0; i < 26; i++) c.cnt[i] = a.cnt[i] - b.cnt[i];
    return c;
}

vector<mset> query(int l, int r)
{
    int n = r - l + 1;
    for (int i = 1; i <= n; i++) totals[i] = zero_mset;
    sendq(l, r);
    for (int i = 1; i <= (n * (n+1))/2; i++) {
        mset st = reads();
        totals[st.siz] = totals[st.siz] + st;
    }
    for (int i = (n/2) + (n%2); i >= 2; i--) {
        totals[i] = totals[i] - totals[i-1];
    }
    for (int i = 1; i < (n/2) + (n%2); i++) {
        totals[i] = totals[i] - totals[i+1];
    }
    vector<mset> ans;
    for (int i = 1; i <= (n/2) + (n%2); i++) {
        ans.push_back(totals[i]);
    }
    return ans;
}

mset ans[105];

int main()
{
    scanf("%d", &N);
    if (N == 1) {
        sendq(1, 1); char s[5];
        scanf("%s", s); printf("! %s", s);
        return 0;
    }
    if (N == 2) {
        char s[5];
        sendq(1, 1);
        scanf("%s", s);
        sendq(2, 2);
        scanf("%s", s + 1);
        printf("! %s", s); return 0;
    }
    vector<mset> q1 = query(1, N);
    vector<mset> q2 = query(2, N);
    ans[1] = query(1, 1)[0];
    int cur = 1;
    int qcur = 0;

    /*for (int i = 0; i < q1.size(); i++) {
        for (int j = 0; j < 26; j++) {
            printf("%d ", q1[i].cnt[j]);
        }
        printf("\n");
    }
    for (int i = 0; i < q2.size(); i++) {
        for (int j = 0; j < 26; j++) {
            printf("%d ", q2[i].cnt[j]);
        }
        printf("\n");
    }*/
    while (1) {
        if (cur == (N/2) + 1) break;
        int oldcur = cur;
        cur = N - cur + 1;
        ans[cur] = q1[qcur] - ans[oldcur];

        if (cur == (N/2) + 1) break;
        oldcur = cur;
        cur = N - cur + 2;
        ans[cur] = q2[qcur] - ans[oldcur];

        qcur++;
    }
    printf("! ");
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 26; j++) {
            if (ans[i].cnt[j]) printf("%c", j + 'a');
        }
    }
    return 0;
}