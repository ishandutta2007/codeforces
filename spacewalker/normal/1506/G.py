from string import ascii_lowercase

def solve(s):
    if len(s) == 0:
        return ""
    lastOcc = {}
    for i, ch in enumerate(s):
        lastOcc[ch] = i
    keyAfter = min(lastOcc.values())
    for ch in ascii_lowercase[::-1]:
        if ch in lastOcc and s.index(ch) <= keyAfter:
            return ch + solve(s[s.index(ch)+1:].replace(ch, ""))
    return '!'




t = int(input())
for tc in range(t):
    print(solve(input()))