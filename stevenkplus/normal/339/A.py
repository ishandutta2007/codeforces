s = [int(x) for x in raw_input().split('+')]
s.sort()
print '+'.join([str(x) for x in s])