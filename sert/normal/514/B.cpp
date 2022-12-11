#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

struct Vector {
	double x, y;
	Vector(int x = 0, int y = 0) : x(x), y(y) {}
};

istream& operator >> (istream& in, Vector& v) {
	in >> v.x >> v.y;
	return in;
}

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

struct Line {
	int A, B, C;
	Line(Vector a, Vector b) {
		A = a.y - b.y;
		B = b.x - a.x;
		C = -A * a.x - B * a.y;

        int g = gcd(A, gcd(B, C));
        A /= g;
        B /= g;
        C /= g;
        if (A < 0) {
            A *= -1;
            B *= -1;
            C *= -1;
        }

        if (A == 0 && B < 0) {
            B *= -1;
            C *= -1;
        }
	}
};

bool operator < (Line a, Line b) {
    if (a.A != b.A) return a.A < b.A;
    if (a.B != b.B) return a.B < b.B;
    return a.C < b.C;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    Vector han, temp;
    cin >> han;
    set<Line> s;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        s.insert(Line(han, temp));
    }
    cout << s.size();

	return 0;
}