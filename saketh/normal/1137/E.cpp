#include <bits/stdc++.h>
using namespace std;
#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct car {
    int inx;
    car *prev = NULL, *next = NULL;

    ll size;
    ll preB, preS;

    ll value = 0;
    ll before = 0;

    car(int inx, ll size = 0, ll preB = 0, ll preS = 0, car *prev = NULL) :
        inx(inx), size(size), preB(preB), preS(preS), prev(prev) {}

    ll eval(ll curB, ll curS) {
        return value + (curB - preB) + before * (curS - preS);
    }

    friend ostream& operator<<(ostream& os, const car& c) {
        return os << "[ " << c.inx << " siz=" << c.size << "bef=" << c.before << " | v=" << c.value << " B=" << c.preB << " S=" << c.preS << " ]";
    }
};

ll elimS(car *a, car *b) {
    ll X = a->value - b->value
         - a->preB + b->preB
         - a->before * a->preS
         + b->before * b->preS;
    //cout << "Comparing cars " << *a << " and " << *b << " X=" << X << endl;

    ll res = X < 0 ? 0 : ((X + a->size - 1) / a->size);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    car *head = NULL, *tail = NULL;
    vector<car*> hist;
    priority_queue<pair<ll, int>> elim;

    auto clear = [&]() {
        while (head != NULL) {
            car *tmp = head->next;
            hist[head->inx] = NULL;
            free(head);
            head = tmp;
        }
    };

    auto erase = [&](car *c) {
        if (c == NULL) return;
        assert(c != head);

        c->prev->next = c->next;
        c->prev->size += c->size;

        if (c == tail) {
            tail = c->prev;
        } else {
            c->next->prev = c->prev;
            elim.push({ -elimS(c->prev, c->next), c->next->inx });
        }

        hist[c->inx] = NULL;
        free(c);
    };

    int N, M;
    cin >> N >> M;

    ll totK = N, totB = 0, totS = 0;

    hist.push_back(new car(hist.size(), N));
    head = tail = hist.back();

    int op, k, b, s;
    while (M--) {
        cin >> op;
        if (op == 1) {
            cin >> k;

            clear();
            while (elim.size()) elim.pop();

            hist.push_back(new car(hist.size(), totK += k, totB, totS));
            head = tail = hist.back();
        } else if (op == 2) {
            cin >> k;

            if (tail->eval(totB, totS) == 0) {
                tail->size += k;
            } else {
                tail->next = new car(hist.size(), k, totB, totS, tail);
                tail->next->before = totK;
                hist.push_back(tail->next);
                elim.push({ -elimS(tail, tail->next), hist.size() - 1 });
                tail = tail->next;
            }

            totK += k;
        } else {
            cin >> b >> s;
            totB += b, totS += s;
            while (elim.size() && -elim.top().first <= totS) {
                erase(hist[elim.top().second]);
                elim.pop();
            }
        }

        cout << 1 + tail->before << " " << tail->eval(totB, totS) << "\n";
    }

    clear();

    return 0;
}