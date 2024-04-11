s = input()
ans = "Correct"
if len(s) < 5:
    ans = "Too weak"
a = 0
b = 0
c = 0
for i in range(len(s)):
    if s[i].isalpha():
        if s[i].isupper():
            a += 1
        else:
            b += 1
    if s[i].isdigit():
        c += 1
if a == 0 or b == 0 or c == 0:
    ans = "Too weak"
print(ans)