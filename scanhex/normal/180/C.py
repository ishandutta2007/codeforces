s = [c for c in input().rstrip()]
small = list(map(lambda x: int('a' <= x <= 'z'), s))
big = list(map(lambda x: int('A' <= x <= 'Z'), s))
prefsmall = [0] * len(s)
prefsmall[0] = small[0]
for i in range(1, len(s)):
    prefsmall[i] = prefsmall[i - 1] + small[i]
suffbig = [0] * len(s)
suffbig[-1] = big[-1]
for i in range(len(s) - 2, -1, -1):
    suffbig[i] = suffbig[i + 1] + big[i]
minx = float('inf')
for i in range(len(s)):
    if prefsmall[i] + suffbig[i] < minx:
        minx = prefsmall[i] + suffbig[i]
print(minx - 1)