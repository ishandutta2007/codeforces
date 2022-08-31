#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int P = (1 << 19);
const int MAXP = 2 * P;
const int MOD = 1e9 + 7;


namespace IO {
    const int BUFFER_SIZE = 4096;
    const int NUMBER_BUFFER = 100;

    FILE *input_stream = stdin;
    FILE *output_stream = stdout;

    char input_buffer[BUFFER_SIZE];
    int input_pos = BUFFER_SIZE;
    int input_read = BUFFER_SIZE;

    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;

    char number_buffer[NUMBER_BUFFER];

    void init(const char *input_file, const char *output_file) {
        input_stream = fopen(input_file, "r");
        output_stream = fopen(output_file, "w");
    }

    void _update_input_buffer() {
        if (input_pos >= input_read && input_read == BUFFER_SIZE) {
            input_read = fread(input_buffer, sizeof(char), BUFFER_SIZE, input_stream);
            input_pos = 0;
        }
    }

    char next_char(bool advance = true) {
        _update_input_buffer();
        return input_buffer[advance ? input_pos++ : input_pos];
    }

    bool on_whitespace() {
        return isspace(next_char(false));
    }

    bool on_digit() {
        return isdigit(next_char(false));
    }

    void skip_whitespace() {
        while (on_whitespace())
            next_char();
    }

    bool input_finished() {
        skip_whitespace();
        return input_pos >= input_read && input_read < BUFFER_SIZE;
    }

    template<typename T>
    void read_int(T &number) {
        skip_whitespace();
        bool negative = next_char(false) == '-';

        if (negative)
            next_char();

        number = 0;

        while (on_digit())
            number = 10 * number + (next_char() - '0');

        if (negative)
            number = -number;
    }

    void flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, output_stream);
        output_pos = 0;
    }

    void write_char(char c) {
        if (output_pos == BUFFER_SIZE)
            flush_output();

        output_buffer[output_pos++] = c;
    }

    template<typename T>
    void write_int(T number, char after = 0) {
        if (number < 0) {
            write_char('-');
            number = -number;
        }

        int length = 0;

        do {
            number_buffer[length++] = number % 10 + '0';
            number /= 10;
        } while (number > 0);

        for (int i = length - 1; i >= 0; i--)
            write_char(number_buffer[i]);

        if (after)
            write_char(after);
    }

    // Make sure flush_output() is called at the end of the program.
    struct Dummy {
        ~Dummy() {
            flush_output();
        }
    } dummy;
}

int N, Q;
int a[MAXN];
int w[MAXN];

ll wseg[MAXP];

void upd (int cloc, ll cdiff, ll ddiff)
{
    cloc = 2 * cloc + P;
    for (int i = 0; i < 18; i++)
    {
        wseg[cloc] += cdiff;
        wseg[cloc+1] += ddiff;
        cloc = (cloc >> 2) << 1;
    }
}

ll ctot, dtot;
ll add (int cloc)
{
    ll res = 0;
    cloc = 2 * cloc + P;
    for (int i = 0; i < 18; i++)
        {
        if (cloc & 2)
        {
            cloc ^= 2;
            res += wseg[cloc];
            dtot -= wseg[cloc+1];
        }
        cloc /= 2;
    }
    return res;
}

int wsearch (ll sgoal)
{
    //cout << "search " << sgoal << "\n";
    int cloc = 2;
    ctot = 0;
    for (int i = 0; i < 18; i++)
    {
        cloc *= 2;
        if (wseg[cloc] + ctot < sgoal)
        {
            ctot += wseg[cloc];
            dtot += wseg[cloc+1] << 1;
            cloc += 2;
        }
    }
    return (cloc - P) / 2;
}

int main()
{
    IO::read_int(N);
    IO::read_int(Q);
    for (int i = 0; i < N; i++)
        IO::read_int(a[i]);
    for (int i = 0; i < N; i++)
        IO::read_int(w[i]);

    for (int i = 0; i < N; i++)
    {
        wseg[2*i+P] = w[i];
        wseg[2*i+1+P] = (a[i] - i) * (ll) w[i] % MOD;
    }
    for (int i = P - 2; i >= 0; i -= 2)
    {
        wseg[i] = wseg[2*i] + wseg[2*i+2];
        wseg[i+1] = wseg[2*i+1] + wseg[2*i+3];
    }

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        IO::read_int(l);
        IO::read_int(r);
        if (l < 0)
        {
            int cloc = -l - 1;
            ll cdiff = r - w[cloc];

            upd (cloc, cdiff, ((a[cloc] - cloc) * cdiff) % MOD);
            w[cloc] = r;
        }
        else
        {
            l--;
            dtot = 0;
            ll sleft = add (l), sright = add (r);
            ll sgoal = (sleft + sright + 1) / 2;
            int mm = wsearch (sgoal);
            ll ws = 2 * ctot - sleft - sright;

            ll res = ws * (a[mm] - mm) - dtot;
            res = res % MOD + MOD;
            if (res >= MOD) res -= MOD;
            IO::write_int((int) res, '\n');
        }
    }
}