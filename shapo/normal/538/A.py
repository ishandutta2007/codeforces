#!/usr/bin/env python3

s = input()
ln = len(s)
ans = "NO"
pat = "CODEFORCES"
cl = len(pat)
if ln > cl:
    for pref_len in range(cl):
        check = s[:pref_len] + s[pref_len - cl:]
        if check == pat:
            ans = "YES"
            break
    if s[:cl] == pat:
        ans = "YES"
print(ans)