class DSU
	def initialize n
		@p = Array.new(n) { |i, v| v = i }
	end
	def find x
		return x if @p[x] == x
		@p[x] = find @p[x]
	end
	def merge a, b
		@p[find(a)] = find(b)
	end
	def query? a, b
		find(a) == find(b)
	end
end

n = gets.to_i
dsu = DSU.new n
p = gets.split.map { |x| x.to_i - 1 }
n.times do |i|
	s = gets.chomp
	n.times do |j|
		if s[j] == '1' and !dsu.query?(i, j)
			dsu.merge i, j
		end
	end
end

ans = Array.new n
n.times do |i|
	if dsu.find(i) == i
		a = []
		b = []
		n.times do |j|
			if dsu.find(j) == i
				a << j
				b << p[j]
			end
		end
		b.sort!
		a.size.times do |j|
			ans[a[j]] = b[j] + 1
		end
	end
end
puts ans.join ' '