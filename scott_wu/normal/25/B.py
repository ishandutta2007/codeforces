import sys

n = int(raw_input())
s = raw_input()

for i in range(n):
    if i % 2 == 0 and i < n - 1 and i > 0:
        sys.stdout.write('-')
    sys.stdout.write(s[i])

sys.stdout.write('\n')