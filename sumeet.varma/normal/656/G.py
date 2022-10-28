f, I, T = map(int, raw_input().split())
c = [0] * I
ans = 0
for i in range(0, f, 1):
   s = raw_input()
   L = list(s)
   for j in range(0, I, 1):
        if L[j] == "Y":
            c[j] = c[j] + 1
            if c[j] == T:
                ans = ans + 1
print ans
# kitten