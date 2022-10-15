n = int(input())
d = input()
s = []
for i in d:
    s.append(int(i))
pos = 0
ans = 10 ** 1000
for i in range(1, len(s)):
    if s[i] == s[i - 1]:
        continue
    else:
        x = s[pos]
        t = [s[j] for j in range(len(s))]
        for j in range(len(t)):
            t[j] = (t[j] + 10 - x) % 10
        A = [0] * n
        for j in range(len(t)):
            A[j] = t[(j + pos) % n]
        a = int(''.join(list(map(str, A))))
        if a < ans:
            ans = a
        pos = i
x = s[pos]
for i in range(len(s)):
    s[i] = (s[i] + 10 - x) % 10
A = [0] * n
for i in range(len(s)):
    A[i] = s[(i + pos) % n]
a = int(''.join(list(map(str, A))))
if a < ans:
    ans = a
print('0' * (n - len(str(ans))) + str(ans))