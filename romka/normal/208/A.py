import sys, re
s = sys.stdin.readline().strip()
s = re.sub("(WUB)+", " ", s)
print s.strip()