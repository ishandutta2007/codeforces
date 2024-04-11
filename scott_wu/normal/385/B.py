s = raw_input()
n = len(s)
#arr = [x for x in range(n-3) if s[x:x+4] == "bear"]

last, ans = 0, 0
for i in range(n-3):
    if s[i:i+4] == "bear":
        ans += (i - last + 1) * (n - i - 3)
        last = i + 1
print ans