s = map (int, raw_input().split('+'))
s.sort()
s = map (str, s)
print '+'.join (s)