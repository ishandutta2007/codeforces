#include <bits/stdc++.h>
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

using namespace std;

enum Type {
  STR, CONCAT, OR, PLUS, STAR, QUESTION
};

struct Expr {
  Type type;
  string str;
  vector<Expr*> e;

  int sx, sy;

  void calcSz() {
    for (auto *ne : e) ne->calcSz();
    switch (type) {
      case STR:
      {
        sx = 3;
        sy = 4 + sz(str);
        break;
      }
      case CONCAT:
      {
        sx = 0;
        sy = 2 * (sz(e) - 1);
        for (auto *ne : e) {
          sx = max(sx, ne->sx);
          sy += ne->sy;
        }
        break;
      }
      case OR:
      {
        sx = sz(e) - 1;
        sy = 0;
        for (auto *ne : e) {
          sx += ne->sx;
          sy = max(sy, ne->sy + 6);
        }
        break;
      }
      case PLUS:
      {
        sx = e[0]->sx + 2;
        sy = e[0]->sy + 6;
        break;
      }
      case STAR:
      {
        sx = e[0]->sx + 5;
        sy = e[0]->sy + 6;
        break;
      }
      case QUESTION:
      {
        sx = e[0]->sx + 3;
        sy = e[0]->sy + 6;
        break;
      }
    }
  }

  void draw(vector<string> &ss, int x0, int y0) {
    switch (type) {
      case STR:
      {
        for (int i = 0; i < 3; ++i)
          ss[x0 + i][y0] = ss[x0 + i][y0 + sy - 1] = '+';
        for (int i = 0; i < sy - 2; ++i)
          ss[x0][y0 + 1 + i] = ss[x0 + 2][y0 + 1 + i] = '-';
        for (int i = 0; i < sz(str); ++i)
          ss[x0 + 1][y0 + 2 + i] = str[i];
        break;
      }
      case CONCAT:
      {
        for (Expr* ne : e) {
          ne->draw(ss, x0, y0);
          y0 += ne->sy + 2;
          if (ne != e.back()) {
            ss[x0 + 1][y0 - 2] = '-';
            ss[x0 + 1][y0 - 1] = '>';
          }
        }
        break;
      }
      case OR:
      {
        for (int x = x0 + 1; x < x0 + sx - e.back()->sx + 2; ++x)
          ss[x][y0] = ss[x][y0 + sy - 1] = '|';
        for (Expr* ne : e) {
          ne->draw(ss, x0, y0 + 3);
          ss[x0 + 1][y0] = '+';
          ss[x0 + 1][y0 + 1] = '-';
          ss[x0 + 1][y0 + 2] = '>';
          ss[x0 + 1][y0 + sy - 1] = '+';
          ss[x0 + 1][y0 + sy - 2] = '>';
          for (int y = y0 + 3 + ne->sy; y < y0 + sy - 2; ++y)
            ss[x0 + 1][y] = '-';
          x0 += ne->sx + 1;
        }
        break;
      }
      case PLUS:
      {
        e[0]->draw(ss, x0, y0 + 3);
        ss[x0 + 1][y0] = '+';
        ss[x0 + 1][y0 + 1] = '-';
        ss[x0 + 1][y0 + 2] = '>';
        ss[x0 + 1][y0 + sy - 1] = '+';
        ss[x0 + 1][y0 + sy - 2] = '>';
        ss[x0 + 1][y0 + sy - 3] = '-';
        for (int x = x0 + 2; x < x0 + sx - 1; ++x)
          ss[x][y0] = ss[x][y0 + sy - 1] = '|';
        ss[x0 + sx - 1][y0] = ss[x0 + sx - 1][y0 + sy - 1] = '+';
        ss[x0 + sx - 1][y0 + 1] = '<';
        for (int y = y0 + 2; y < y0 + sy - 1; ++y)
          ss[x0 + sx - 1][y] = '-';
        break;
      }
      case STAR:
      {
        ++x0;
        e[0]->draw(ss, x0 + 2, y0 + 3);
        for (int y = y0 + 1; y < y0 + sy - 2; ++y)
          ss[x0][y] = '-';
        ss[x0][y0] = ss[x0][y0 + sy - 1] = '+';
        ss[x0][y0 + sy - 2] = '>';
        ss[x0 + 1][y0] = ss[x0 + 1][y0 + sy - 1] = '|';
        ss[x0 + 2][y0] = ss[x0 + 2][y0 + sy - 1] = '|';
        ss[x0 + 3][y0] = ss[x0 + 3][y0 + sy - 1] = '+';
        ss[x0 + 3][y0 + 1] = ss[x0 + 3][y0 + sy - 3] = '-';
        ss[x0 + 3][y0 + 2] = ss[x0 + 3][y0 + sy - 2] = '>';
        for (int x = x0 + 4; x < x0 - 2 + sx; ++x)
          ss[x][y0] = ss[x][y0 + sy - 1] = '|';
        ss[x0 + sx - 2][y0] = ss[x0 + sx - 2][y0 + sy - 1] = '+';
        ss[x0 + sx - 2][y0 + 1] = '<';
        for (int y = y0 + 2; y < y0 + sy - 1; ++y)
          ss[x0 + sx - 2][y] = '-';
        break;
      }
      case QUESTION:
      {
        ++x0;
        e[0]->draw(ss, x0 + 2, y0 + 3);
        for (int y = y0 + 1; y < y0 + sy - 2; ++y)
          ss[x0][y] = '-';
        ss[x0][y0] = ss[x0][y0 + sy - 1] = '+';
        ss[x0][y0 + sy - 2] = '>';
        ss[x0 + 1][y0] = ss[x0 + 1][y0 + sy - 1] = '|';
        ss[x0 + 2][y0] = ss[x0 + 2][y0 + sy - 1] = '|';
        ss[x0 + 3][y0] = ss[x0 + 3][y0 + sy - 1] = '+';
        ss[x0 + 3][y0 + 1] = ss[x0 + 3][y0 + sy - 3] = '-';
        ss[x0 + 3][y0 + 2] = ss[x0 + 3][y0 + sy - 2] = '>';
        break;
      }
    }
  }
};

namespace parser {
  string s;
  int i = 0;

  Expr* parse();

  Expr* parse2() {
    Expr *e;
    if (s[i] == '(') {
      ++i;
      e = parse();
      assert(i < sz(s) && s[i] == ')');
      ++i;
    } else {
      assert('A' <= s[i] && s[i] <= 'Z');
      e = new Expr;
      e->type = STR;
      e->str += s[i++];
      while (true) {
        if (i == sz(s)) break;
        if (!('A' <= s[i] && s[i] <= 'Z')) break;
        if (i + 1 != sz(s) && (s[i + 1] == '?' || s[i + 1] == '+' || s[i + 1] == '*')) break;
        e->str += s[i++];
      }
    }
    while (i != sz(s)) {
      if (s[i] == '*') {
        Expr *ne = new Expr;
        ne->type = STAR;
        ne->e = {e};
        e = ne;
        ++i;
        continue;
      }
      if (s[i] == '+') {
        Expr *ne = new Expr;
        ne->type = PLUS;
        ne->e = {e};
        e = ne;
        ++i;
        continue;
      }
      if (s[i] == '?') {
        Expr *ne = new Expr;
        ne->type = QUESTION;
        ne->e = {e};
        e = ne;
        ++i;
        continue;
      }
      break;
    }
    return e;
  }

  Expr* parse1() {
    vector<Expr*> e;
    while (true) {
      e.push_back(parse2());
      if (i == sz(s) || s[i] == '|' || s[i] == ')') break;
    }
    if (sz(e) == 1) return e[0];
    Expr *ne = new Expr;
    ne->type = CONCAT;
    ne->e = e;
    return ne;
  }

  Expr* parse() {
    vector<Expr*> e;
    while (true) {
      e.push_back(parse1());
      if (s[i] == ')' || i == sz(s)) break;
      if (s[i] == '|') ++i;
      else assert(false);
    }
    if (sz(e) == 1) return e[0];
    Expr *ne = new Expr;
    ne->type = OR;
    ne->e = e;
    return ne;
  }
}

int main() {
  cin >> parser::s;

  Expr* root = parser::parse();
  root->calcSz();

  vector<string> ss = vector<string>(root->sx, string(root->sy + 6, ' '));
  cout << sz(ss) << " " << sz(ss[0]) << "\n";
  ss[1][0] = 'S';
  ss[1][1] = '-';
  ss[1][2] = '>';
  ss[1][sz(ss[1]) - 3] = '-';
  ss[1][sz(ss[1]) - 2] = '>';
  ss[1][sz(ss[1]) - 1] = 'F';
  root->draw(ss, 0, 3);
  for (auto const& s : ss)
    cout << s << "\n";
}